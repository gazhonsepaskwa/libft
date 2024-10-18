/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:07:05 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/18 09:21:28 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ps;
	size_t			i;

	if (n == 0)
		return ;
	ps = (unsigned char *)s;
	i = 0;
	while (i < n)
		ps[i++] = 0;
}
