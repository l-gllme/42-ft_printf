/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_di_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:15:23 by lguillau          #+#    #+#             */
/*   Updated: 2021/12/06 15:09:31 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_flag_width_di2(int nb, t_flags flags, int count)
{
	if (flags.justify)
	{
		if (nb < 0)
		{
			count += ft_putchar_count('-');
			count += ft_putnbr_count((long long int)nb * -1, 0);
		}
		if (nb >= 0)
			count += ft_putnbr_count(nb, 0);
	}
	else if (!flags.justify)
	{
		if (nb < 0)
			count += ft_putchar_count('-');
		if (nb < 0)
			count += ft_putnbr_count((long long int)nb * -1, 0);
		if (nb >= 0)
			count += ft_putnbr_count(nb, 0);
	}
	return (count);
}

int	ft_flag_width_di(int nb, t_flags flags, int len, int count)
{
	int	i;
	int	l;

	i = -1;
	l = 0;
	if (flags.space && nb >= 0)
	{
		count += ft_putchar_count(' ');
		l = 1;
	}
	if (flags.justify && nb < 0)
	{
		l = 1;
		i--;
	}
	if (flags.justify)
		count += ft_flag_width_di2(nb, flags, 0);
	while (++i < flags.width - len - l)
		count += ft_putchar_count(' ');
	if (!flags.justify)
		count += ft_flag_width_di2(nb, flags, 0);
	return (count);
}

int	ft_print_width_di(int d, t_flags flags)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa(d);
	if (flags.dot && d >= 0)
		count += ft_flag_dot_di(d, flags, (int)ft_strlen(str), count);
	else if (flags.dot && d < 0)
		count += ft_flag_dot_di_neg(d, flags, (int)ft_strlen(str), count);
	else if (flags.plus && d >= 0)
		count += ft_flag_plus_di(d, flags, (int)ft_strlen(str), count);
	else if (flags.zero && !flags.justify)
		count += ft_flag_zero_di(d, flags, (int)ft_strlen(str), count);
	else
		count += ft_flag_width_di(d, flags, (int)ft_strlen(str), count);
	free(str);
	return (count);
}
