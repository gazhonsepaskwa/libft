/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:21:39 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/25 09:48:52 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;
	size_t				i;

	if (!dst && !src)
		return (0);
	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	i = -1;
	while (++i < n)
		pdst[i] = psrc[i];
	return (dst);
}
