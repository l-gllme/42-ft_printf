/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:23:06 by lguillau          #+#    #+#             */
/*   Updated: 2021/12/06 14:39:11 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_fill_struct(va_list argv, t_flags flags, char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == '%')
		{
			flags = ft_init_flags_struct();
			flags = ft_parse(s, flags, i + 1);
			count += ft_conv(flags.conv, argv, flags);
			i += flags.numbers;
		}
		else
		{
			count += ft_putchar_count(s[i]);
			i++;
		}
	}
	return (count);
}

static t_flags	ft_parse1(char *s, int i, t_flags flags)
{
	int	pr;

	pr = 0;
	if (s[i] == '.')
	{
		flags.dot = '.';
		pr = 0;
		while (s[i + 1] >= '0' && s[i + 1] <= '9')
		{
			pr = pr * 10 + s[i + 1] - '0';
			flags.preci = pr;
			i++;
			flags.numbers += 1;
		}
	}
	return (flags);
}

static t_flags	ft_parse2(char *s, int i, t_flags flags)
{
	int	nb;

	nb = 0;
	if (s[i] >= '1' && s[i] <= '9')
	{
		while (s[i] >= '0' && s[i] <= '9')
		{
			nb = nb * 10 + (s[i] - '0');
			flags.width = nb;
			i++;
			flags.numbers += 1;
		}
		flags.numbers += -1;
	}
	return (flags);
}

static t_flags	ft_parse3(char c, t_flags flags, int i, char *s)
{
	if (c == '0')
		flags.zero = '0';
	else if (c == '-')
		flags.justify = '-';
	else if (c == '#')
		flags.sharp = '#';
	else if (c == ' ')
		flags.space = ' ';
	else if (c == '+')
		flags.plus = '+';
	else if (c == '.')
		flags = ft_parse1(s, i, flags);
	return (flags);
}

t_flags	ft_parse(char *s, t_flags flags, int i)
{
	flags.numbers = 1;
	while (s[i] && s[i] != 'c' && s[i] != 's' && s[i] != 'p'
		&& s[i] != 'd' && s[i] != 'i' && s[i] != 'u'
		&& s[i] != 's' && s[i] != 'x' && s[i] != 'X' && s[i] != '%')
	{
		if (s[i] == '0' || s[i] == '-' || s[i] == '#'
			|| s[i] == ' ' || s[i] == '+' || s[i] == '.')
			flags = ft_parse3(s[i], flags, i, s);
		if (s[i] == '.')
			while (s[i + 1] >= '0' && s[i + 1] <= '9')
				i++;
		else if (s[i] >= '1' && s[i] <= '9' && flags.width == 0)
		{
			flags = ft_parse2(s, i, flags);
			while (s[i] >= '0' && s[i] <= '9')
				i++;
			i--;
		}
		i++;
		flags.numbers += 1;
	}
	flags.conv = s[i];
	flags.numbers += 1;
	return (flags);
}
