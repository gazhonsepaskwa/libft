/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:37:46 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/25 09:12:19 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	if (!dest && !src)
		return (0);
	pdst = (unsigned char *)dest;
	psrc = (const unsigned char *)src;
	if (pdst < psrc)
	{
		while (n--)
			*pdst++ = *psrc++;
	}
	else
	{
		pdst += n;
		psrc += n;
		while (n--)
			*(--pdst) = *(--psrc);
	}
	return (dest);
}
