/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:17:16 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/21 09:44:24 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((size_t)start + len > ft_strlen(s))
		sub = ft_calloc(ft_strlen(s) - (size_t)start + 1, sizeof(char));
	else
		sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (sub && i < len && s[start + i] != 0)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
