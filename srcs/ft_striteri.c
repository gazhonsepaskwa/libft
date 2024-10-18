/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:17:33 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/18 11:11:59 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t		len;
	size_t		i;

	if (!s || !f)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
