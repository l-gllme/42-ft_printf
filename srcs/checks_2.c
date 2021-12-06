/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:44:34 by lguillau          #+#    #+#             */
/*   Updated: 2021/12/06 14:46:08 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_check_pr(va_list argv, t_flags flags)
{
	int	count;

	(void)argv;
	count = 0;
	if (flags.conv == '%')
		count += ft_putchar_count('%');
	return (count);
}

int	ft_check_x(va_list argv, t_flags flags)
{
	int	count;
	int	nb;
	int	len;

	nb = va_arg(argv, int);
	len = ft_unsigned_putnbr_exa_len(nb, flags.conv, 0);
	count = 0;
	if (flags.dot)
		count += ft_flag_dot_x(nb, flags, len, count);
	else if (flags.zero)
		count += ft_flag_zero_x(nb, flags, len, count);
	else if (flags.width)
		count += ft_flag_width_x(nb, flags, len, count);
	else if (flags.sharp)
		count += ft_flag_sharp_x(nb, flags, len, count);
	else
		count += ft_unsigned_putnbr_exa_count(nb, flags.conv, 0);
	return (count);
}

int	ft_check_u(va_list argv, t_flags flags)
{
	int				count;
	unsigned int	nb;
	int				len;

	nb = va_arg(argv, int);
	len = ft_unsigned_putnbr_len(nb, 0);
	count = 0;
	if (flags.dot)
		count += ft_flag_dot_u(nb, flags, len, count);
	else if (flags.width)
		count += ft_flag_width_u(nb, flags, len, count);
	else
		count += ft_unsigned_putnbr_count(nb, 0);
	return (count);
}
