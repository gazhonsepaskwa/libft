/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:15:11 by nalebrun          #+#    #+#             */
/*   Updated: 2024/11/25 16:15:33 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	is_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' \
			|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	ft_put_p(va_list ap)
{
	int	count;

	if (ft_put_s("0x") == -1)
		return (-1);
	count = ft_put_uli_base((unsigned long)va_arg(ap, void *), BASE16);
	if (count == -1)
		return (-1);
	return (count + 2);
}

static int	formater(va_list ap, const char *fstr)
{
	if (*fstr == 'c')
		return (ft_put_c((char)va_arg(ap, int)));
	if (*fstr == 's')
		return (ft_put_s((char *)va_arg(ap, char *)));
	if (*fstr == 'p')
		return (ft_put_p(ap));
	if (*fstr == 'd' || *fstr == 'i')
		return (ft_put_i((int)va_arg(ap, int)));
	if (*fstr == 'u')
		return (ft_put_ui((unsigned int)va_arg(ap, unsigned int)));
	if (*fstr == 'x')
		return (ft_put_ui_base((unsigned int)va_arg(ap, int), BASE16));
	if (*fstr == 'X')
		return (ft_put_ui_base((unsigned int)va_arg(ap, int), BASE16UP));
	else
		return (ft_put_s("%"));
}

int	ft_printf(const char *fstr, ...)
{
	va_list	ap;
	int		count;
	int		tmp;

	count = 0;
	va_start(ap, fstr);
	while (*fstr != 0)
	{
		if (*fstr == '%' && is_format(*(fstr + 1)))
			tmp = formater(ap, ++fstr);
		else
			tmp = ft_put_c(*fstr);
		if (tmp == -1)
			return (-1);
		count += tmp;
		fstr++;
	}
	va_end(ap);
	return (count);
}

int	ft_debug(const char *fstr, ...)
{
	va_list	ap;
	int		count;
	int		tmp;

	count = 0;
	va_start(ap, fstr);
	ft_put_s("\033[33m[DEBUG]\033[0m");
	while (*fstr != 0)
	{
		if (*fstr == '%' && is_format(*(fstr + 1)))
			tmp = formater(ap, ++fstr);
		else
			tmp = ft_put_c(*fstr);
		if (tmp == -1)
			return (-1);
		count += tmp;
		fstr++;
	}
	va_end(ap);
	return (count);
}
