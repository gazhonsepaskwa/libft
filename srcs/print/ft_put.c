/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:09:26 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/25 16:15:47 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_put_c(char c)
{
	return (write(1, &c, 1));
}

int	ft_put_s(char *s)
{
	if (!s)
		return (ft_put_s("(null)"));
	return (write(1, s, ft_strlen(s)));
}

int	ft_put_i(int n)
{
	int		count;
	int		tmp;
	long	nb;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count ++;
		nb = -nb;
	}
	if (nb >= 10)
	{
		tmp = ft_put_i(nb / 10);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	tmp = ft_put_c((nb % 10) + '0');
	if (tmp == -1)
		return (-1);
	return (tmp + count);
}

int	ft_put_ui(unsigned int n)
{
	char	c;
	int		count;
	int		tmp;

	count = 0;
	if (n >= 10)
	{
		tmp = ft_put_ui(n / 10);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	c = (n % 10) + '0';
	tmp = write(1, &c, 1);
	if (tmp == -1)
		return (-1);
	return (tmp + count);
}
