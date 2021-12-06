/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:46:00 by lguillau          #+#    #+#             */
/*   Updated: 2021/12/06 14:22:47 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_len_addr(size_t num)
{
	char	str[255];
	int		i;
	int		count;

	if ((void *)num == NULL)
		return (3);
	i = 0;
	count = 0;
	while (num > 0)
	{
		str[i] = ("0123456789abcdef"[num % 16]);
		num = num / 16;
		i++;
		count++;
	}
	str[i] = 0;
	return (count + 2);
}

int	ft_print_addr_count(size_t num)
{
	char	str[255];
	int		i;
	int		count;

	if ((void *)num == NULL)
		return (ft_putstr_count("0x0"));
	i = 0;
	count = 0;
	while (num > 0)
	{
		str[i] = ("0123456789abcdef"[num % 16]);
		num = num / 16;
		i++;
		count++;
	}
	str[i] = 0;
	write(1, "0x", 2);
	while (--i >= 0)
	{
		write(1, &str[i], 1);
	}
	return (count + 2);
}

int	ft_putnbr_count(long long int n, int i)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		i++;
		nb = n * -1;
	}
	else
		nb = n;
	if (nb > 9)
	{
		i = ft_putnbr_count(nb / 10, i);
		i = ft_putnbr_count(nb % 10, i);
	}
	else
		i += ft_putchar_count(nb + '0');
	return (i);
}

int	ft_putchar_count(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
