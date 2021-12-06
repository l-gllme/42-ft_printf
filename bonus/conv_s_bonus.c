/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:08:10 by lguillau          #+#    #+#             */
/*   Updated: 2021/12/06 14:18:27 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_flag_dot_s(char *s, t_flags flags, int count)
{
	int	i;

	i = -1;
	if (!flags.justify && flags.width)
		while (++i < flags.width - flags.preci)
			count += ft_putchar_count(' ');
	i = -1;
	while (++i < flags.preci && s[i])
		count += ft_putchar_count(s[i]);
	if (flags.justify && flags.width)
		while (++i < flags.width + 1)
			count += ft_putchar_count(' ');
	return (count);
}

int	ft_flag_width_s(char *s, t_flags flags, int count)
{
	int	i;

	i = -1;
	if (!flags.justify)
		while (i++ < flags.width - (int)ft_strlen(s) - 1)
			count += ft_putchar_count(' ');
	count += ft_putstr_count(s);
	if (flags.justify)
		while (i++ < flags.width - (int)ft_strlen(s) - 1)
			count += ft_putchar_count(' ');
	return (count);
}
