/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:21:30 by lguillau          #+#    #+#             */
/*   Updated: 2021/12/06 15:02:45 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

t_flags	ft_init_flags_struct(void)
{
	t_flags	flags;

	flags.conv = 0;
	flags.width = 0;
	flags.plus = 0;
	flags.justify = 0;
	flags.space = 0;
	flags.zero = 0;
	flags.sharp = 0;
	flags.dot = 0;
	flags.preci = 0;
	flags.numbers = 0;
	return (flags);
}

int	ft_printf(const char *format, ...)
{
	int		return_len;
	va_list	argv;
	t_flags	flags;

	flags = ft_init_flags_struct();
	va_start(argv, format);
	return_len = ft_fill_struct(argv, flags, (char *)format);
	va_end(argv);
	return (return_len);
}
