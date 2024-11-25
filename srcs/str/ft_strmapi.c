/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:32:03 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/25 16:16:28 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*out;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	out = (char *)ft_calloc(len + 1, sizeof(char));
	if (!out)
		return (NULL);
	i = -1;
	while (++i < len)
		out[i] = f(i, s[i]);
	out[len] = '\0';
	return (out);
}
