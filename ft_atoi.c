/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:00:41 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/22 16:24:58 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	else
		return (0);
}

static int ft_signer(char c, int *i)
{
  int sign;

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

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
  int	res;
  int count;

	res = 0;
	i = 0;
  sign = ft_signer(str[i], &i);
	while (ft_isspace(str[i]))
		i++;
  while (str[i] == '0')
    i++;
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
    count++;
		i++;
    if (count > 18 && sign == 1)
      return -1;
    if (count > 18 && sign == -1)
      return 0;
	}
	return (res *= sign);
}

