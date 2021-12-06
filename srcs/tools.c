/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:53:17 by lguillau          #+#    #+#             */
/*   Updated: 2021/12/02 13:10:21 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_unsigned_putnbr_exa_count(unsigned int num, char c, int i)
{
	unsigned int	nb;
	char			*hex;

	nb = num;
	if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (nb >= 16)
	{
		i = ft_unsigned_putnbr_exa_count(nb / 16, c, i);
		i += ft_putchar_count(hex[nb % 16]);
	}
	else
		i += ft_putchar_count(hex[nb]);
	return (i);
}

int	ft_unsigned_putnbr_exa_len(unsigned int num, char c, int i)
{
	unsigned int	nb;
	char			*hex;

	nb = num;
	if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (nb >= 16)
	{
		i = ft_unsigned_putnbr_exa_len(nb / 16, c, i);
		i++;
	}
	else
		i++;
	return (i);
}
