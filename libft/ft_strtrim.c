/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:18:21 by lguillau          #+#    #+#             */
/*   Updated: 2021/11/24 12:06:11 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static	int	total_len(char const *s, char const *set)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (is_set(s[i], set) && s[i])
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		i++;
		len++;
	}
	i--;
	while (is_set(s[i], set) && s[i])
	{
		i--;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	j;
	char	*s;

	if (!s1)
		return (NULL);
	i = 0;
	j = 0;
	len = total_len(s1, set);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	while (is_set(s1[i], set) && s1[i])
		i++;
	if (s1[i])
	{
		while (j < len)
		{
			s[j] = s1[j + i];
			j++;
		}
	}
	s[j] = 0;
	return (s);
}
