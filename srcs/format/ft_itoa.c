/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:36:46 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/27 12:59:05 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	*ft_itoamem(long int n)
{
	int		i;
	char	*res;
	int		sign;

	i = 0;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	res = malloc(((i + 1) + sign + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[i + 1 + sign] = '\0';
	ft_memset(res, 48, ((i + 1) + sign) * sizeof(char));
	return (res);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			i;
	long int	num;

	num = n;
	res = ft_itoamem(num);
	if (!res)
		return (NULL);
	i = 0;
	if (num < 0)
	{
		res[i] = '-';
		num *= -1;
	}
	i = ft_strlen(res);
	res[i] = '\0';
	i--;
	while (num > 9)
	{
		res[i--] = (num % 10) + '0';
		num /= 10;
	}
	res[i] = num + '0';
	return (res);
}
