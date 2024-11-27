/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:45:42 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/27 12:50:04 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include "gnl.h"

void	free_buf(char **tab)
{
	if (tab && *tab)
	{
		free(*tab);
		*tab = NULL;
	}
}

char	*build_tab(char *tab, char *buffer, int i)
{
	char	*ret;
	size_t	t_len;
	size_t	b_len;

	b_len = ft_gstrlen(buffer, -2);
	t_len = ft_gstrlen(tab, i);
	ret = malloc(b_len + t_len + 1);
	if (!ret)
	{
		free(tab);
		return (NULL);
	}
	if (tab)
	{
		ft_strlcpy(ret, tab, t_len + 1);
		ft_strlcat(&ret[t_len], buffer, b_len + t_len + 1);
		free(tab);
	}
	else
		ft_strlcpy(ret, buffer, b_len + 1);
	return (ret);
}

char	*get_the_line(char **tab, int i)
{
	char	*line;
	char	*new_tab;
	size_t	len;
	char	*nl_pos;

	nl_pos = ft_strichr(*tab, '\n', i);
	if (!nl_pos)
		return (NULL);
	len = nl_pos - *tab + 1;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *tab, len + 1);
	line[len] = '\0';
	new_tab = ft_strdup(*tab + len);
	if (!new_tab)
	{
		free(line);
		return (NULL);
	}
	free(*tab);
	*tab = new_tab;
	return (line);
}

int	read_file(int fd, char **tab, int i)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		if (bytes_read == -1)
			free_buf(&tab[fd]);
		return (bytes_read);
	}
	buffer[bytes_read] = '\0';
	tab[fd] = build_tab(tab[fd], buffer, i);
	if (!tab[fd])
		return (-1);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*tab[256];
	char		*next_line;
	int			i;

	i = -1;
	next_line = NULL;
	if (fd < 0 || fd >= 256 || BUFFER_SIZE == 0)
		return (NULL);
	while (++i || 1)
	{
		next_line = get_the_line(&tab[fd], i);
		if (next_line)
			return (next_line);
		if (read_file(fd, tab, i) <= 0)
			break ;
	}
	if (tab[fd] && *tab[fd])
	{
		next_line = tab[fd];
		tab[fd] = NULL;
		return (next_line);
	}
	free(tab[fd]);
	tab[fd] = NULL;
	return (NULL);
}
