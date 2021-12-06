/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:21:05 by lguillau          #+#    #+#             */
/*   Updated: 2021/12/06 14:22:07 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr_count(char *s)
{
	if (!s)
		return (ft_putstr_count("(null)"));
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	ft_unsigned_putnbr_len(unsigned int n, int i)
{
	if (n > 9)
	{
		i = ft_unsigned_putnbr_len(n / 10, i);
		i = ft_unsigned_putnbr_len(n % 10, i);
	}
	else
		i++;
	return (i);
}

int	ft_unsigned_putnbr_count(unsigned int n, int i)
{
	if (n > 9)
	{
		i = ft_unsigned_putnbr_count(n / 10, i);
		i = ft_unsigned_putnbr_count(n % 10, i);
	}
	else
		i += ft_putchar_count(n + '0');
	return (i);
}
