/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:01:21 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/25 16:15:43 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_put_ui_base(unsigned int nbr, char *base)
{
	unsigned int	base_len;
	int				count;
	int				tmp;

	count = 0;
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	if (nbr >= base_len)
	{
		tmp = ft_put_ui_base(nbr / base_len, base);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	tmp = write(1, &base[nbr % base_len], 1);
	if (tmp == -1)
		return (-1);
	return (tmp + count);
}

int	ft_put_uli_base(unsigned long int nbr, char *base)
{
	unsigned long	base_len;
	int				count;
	int				tmp;

	count = 0;
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	if (nbr >= base_len)
		count += ft_put_uli_base(nbr / base_len, base);
	tmp = write(1, &base[nbr % base_len], 1);
	if (tmp == -1)
		return (-1);
	return (tmp + count);
}
