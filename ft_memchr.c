/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:38:35 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/25 09:49:55 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ps;

	ps = (const unsigned char *)s;
	i = -1;
	while (++i < n)
		if (ps[i] == (unsigned char)c)
			return ((char *)&ps[i]);
	return (NULL);
}
