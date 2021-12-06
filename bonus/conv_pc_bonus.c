/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:47:14 by lguillau          #+#    #+#             */
/*   Updated: 2021/12/06 14:52:46 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_width_p(void *p, t_flags flags)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	if (!flags.justify)
	{
		while (++i < flags.width - (int)ft_len_addr((size_t)p))
			count += ft_putchar_count(' ');
		count += ft_print_addr_count((size_t)p);
	}
	else
	{
		count += ft_print_addr_count((size_t)p);
		while (++i < flags.width - (int)ft_len_addr((size_t)p))
			count += ft_putchar_count(' ');
	}
	return (count);
}

int	ft_print_width_c(char c, char j, int nb)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	if (j != 0)
	{
		count = ft_putchar_count(c);
		while (++i < nb - 1)
			count += ft_putchar_count(' ');
	}
	else
	{
		while (++i < nb - 1)
			count += ft_putchar_count(' ');
		count += ft_putchar_count(c);
	}
	return (count);
}
