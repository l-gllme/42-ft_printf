/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:44:37 by lguillau          #+#    #+#             */
/*   Updated: 2021/12/06 14:42:08 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_conv(char c, va_list argv, t_flags flags)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_check_c(argv, flags);
	if (c == 's')
		count = ft_check_s(argv, flags);
	if (c == 'd' || c == 'i')
		count = ft_check_di(argv, flags);
	if (c == 'p')
		count = ft_check_p(argv, flags);
	if (c == 'u')
		count = ft_check_u(argv, flags);
	if (c == 'x' || c == 'X')
		count = ft_check_x(argv, flags);
	if (c == '%')
		count = ft_check_pr(argv, flags);
	return (count);
}

int	ft_check_di(va_list argv, t_flags flags)
{
	int	count;
	int	nb;

	nb = va_arg(argv, int);
	count = 0;
	if (flags.width || flags.dot)
		count += ft_print_width_di(nb, flags);
	else if (flags.plus && nb >= 0)
	{
		count += ft_putchar_count('+');
		count += ft_putnbr_count(nb, 0);
	}
	else if (flags.space && nb >= 0)
	{
		count += ft_putchar_count(' ');
		count += ft_putnbr_count(nb, 0);
	}
	else
		count += ft_putnbr_count(nb, 0);
	return (count);
}

int	ft_check_s(va_list argv, t_flags flags)
{
	int		count;
	char	*str;

	count = 0;
	str = va_arg(argv, char *);
	if (!str)
		str = "(null)";
	if (flags.dot)
		count += ft_flag_dot_s(str, flags, count);
	else if (flags.width)
		count = ft_flag_width_s(str, flags, count);
	else
		count = ft_putstr_count(str);
	return (count);
}

int	ft_check_c(va_list argv, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.width)
		count = ft_print_width_c(va_arg(argv, int), flags.justify, flags.width);
	else
		count = ft_putchar_count(va_arg(argv, int));
	return (count);
}

int	ft_check_p(va_list argv, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.width)
		count = ft_print_width_p(va_arg(argv, void *), flags);
	else
		count += ft_print_addr_count((size_t)va_arg(argv, void *));
	return (count);
}
