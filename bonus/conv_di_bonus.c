/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_di_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:17:09 by lguillau          #+#    #+#             */
/*   Updated: 2021/12/06 14:18:46 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_flag_dot_di2(t_flags flags, int nb, int len, int count)
{
	int	i;
	int	pone;
	int	len0;

	i = -1;
	len0 = 0;
	pone = 0;
	if (nb < 0 && flags.preci >= len)
		len0 = 1;
	if (flags.plus || flags.space)
		pone = 1;
	if (flags.preci <= len)
		flags.preci = 0;
	else
		len = 0;
	while (++i < flags.width - flags.preci - pone - len - len0)
		count += ft_putchar_count(' ');
	return (count);
}	

int	ft_flag_dot_di_neg(int nb, t_flags flags, int len, int count)
{
	int	i;

	i = -1;
	if (flags.width && !flags.justify)
		count += ft_flag_dot_di2(flags, nb, len, 0);
	count += ft_putchar_count('-');
	while (++i < flags.preci - len + 1)
		count += ft_putchar_count('0');
	count += ft_putnbr_count((long long int)nb * -1, 0);
	if (flags.width && flags.justify)
		count += ft_flag_dot_di2(flags, nb, len, 0);
	return (count);
}

int	ft_flag_dot_di(int nb, t_flags flags, int len, int count)
{
	int	i;
	int	pone;

	i = -1;
	pone = 0;
	if (nb == 0 && (!flags.preci || flags.preci == 0))
		len = 0;
	if (flags.plus || flags.space)
		pone = 1;
	if (flags.width && !flags.justify)
		count += ft_flag_dot_di2(flags, nb, len, 0);
	if (flags.plus && nb >= 0)
		count += ft_putchar_count('+');
	if (flags.space && !flags.plus && nb >= 0)
		count += ft_putchar_count(' ');
	while (++i < flags.preci - len)
		count += ft_putchar_count('0');
	if (nb == 0 && (!flags.preci || flags.preci == 0))
		count += 0;
	else if (nb >= 0)
		count += ft_putnbr_count(nb, 0);
	if (flags.width && flags.justify)
		count += ft_flag_dot_di2(flags, nb, len, 0);
	return (count);
}

int	ft_flag_plus_di(int nb, t_flags flags, int len, int count)
{
	int		i;
	char	c;

	i = -1;
	c = ' ';
	if (flags.zero)
		c = '0';
	if (flags.justify)
	{
		count += ft_putchar_count('+');
		count += ft_putnbr_count(nb, 0);
		while (++i < flags.width - len - 1)
			count += ft_putchar_count(' ');
	}
	if (!flags.justify)
	{
		count += ft_putchar_count('+');
		while (++i < flags.width - len - 1)
			count += ft_putchar_count(c);
		count += ft_putnbr_count(nb, 0);
	}
	return (count);
}

int	ft_flag_zero_di(int nb, t_flags flags, int len, int count)
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
	if (nb < 0)
	{
		count += ft_putchar_count('-');
		l = 1;
		i--;
	}
	while (++i < flags.width - len - l)
		count += ft_putchar_count('0');
	if (nb >= 0)
		count += ft_putnbr_count(nb, 0);
	if (nb < 0)
		count += ft_putnbr_count((long long int)nb * -1, 0);
	return (count);
}
