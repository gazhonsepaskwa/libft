/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:48:02 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/27 12:53:32 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include "gnl.h"

size_t	ft_gstrlen(const char *str, int j)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (j == 0 || j == -2)
	{
		while (str[i])
			i++;
		return (i);
	}
	else
	{
		if (j > 0)
			j--;
		if (j != 0)
			i += (BUFFER_SIZE * j) - 1;
		while (str[i])
			i++;
		return (i);
	}
}

char	*ft_strichr(const char *s, int c, int i)
{
	char	*str;
	char	ch;

	if (!s)
		return (0);
	if (i > 0)
		i--;
	ch = c;
	str = (char *)s;
	if (i != 0)
		str += (BUFFER_SIZE * i) - 1;
	while (*str)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	if ((ch == 0) && (*str == 0))
		return (str);
	return (0);
}
