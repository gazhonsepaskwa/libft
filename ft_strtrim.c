/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:42:56 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/16 15:02:56 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_instr(int c, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

static int	ft_gettrimstart(const char *str, const char *set)
{
	int	i;

	i = 0;
	while (ft_instr(str[i], (char *)set) && str[i])
		i++;
	return (i);
}

static int	ft_gettrimend(const char *str, const char *set)
{
	int	i;

	i = 0;
	while (ft_instr(str[ft_strlen(str) - i - 1], (char *)set))
		i++;
	return (i);
}

static void	trloop(char *cpy, const char *s1, size_t trimstart, size_t trimend)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s1) - (trimstart + trimend))
	{
		cpy[i] = s1[trimstart + i];
		i++;
	}
	cpy[i] = 0;
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*cpy;
	size_t	trimstart;
	size_t	trimend;

	if(!s1 || !set)
		return NULL;
	cpy = (char *)s1;
	trimstart = ft_gettrimstart(s1, set);
	if (trimstart == ft_strlen(s1))
		return (ft_strdup(""));
	trimend = ft_gettrimend(s1, set);
	cpy = ft_calloc(ft_strlen(s1) - (trimstart + trimend) + 1, sizeof(char));
	if (!cpy)
		return (NULL);
	trloop(cpy, s1, trimstart, trimend);
	return (cpy);
}
