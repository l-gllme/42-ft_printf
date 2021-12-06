/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:33:15 by lguillau          #+#    #+#             */
/*   Updated: 2021/11/24 11:31:40 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;
	size_t	len;

	i = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	len = size - d_len - 1;
	if (d_len < size - 1 && size > 0)
	{
		while (src[i] && i < len)
		{	
			dst[d_len + i] = src[i];
			i++;
		}
		dst[d_len + i] = 0;
	}
	if (d_len >= size)
		d_len = size;
	return (d_len + s_len);
}
