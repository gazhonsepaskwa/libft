/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:00:41 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/27 12:59:01 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	else
		return (0);
}

static int	ft_signer(char c, int *i)
{
	int	sign;

	sign = 1;
	if (c == '-')
	{
		sign *= -1;
		(*i)++;
	}
	else if (c == '+')
		(*i)++;
	return (sign);
}

static int	ft_signed(int sign)
{
	if (sign == -1)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;
	int		current_digit;

	if (!str)
		return (-1);
	res = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = ft_signer(str[i], &i);
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i]))
	{
		current_digit = str[i] - '0';
		if (res > (LONG_MAX - current_digit) / 10)
			return (ft_signed(sign));
		res = (res * 10) + current_digit;
		i++;
	}
	return ((int)(res *= sign));
}
