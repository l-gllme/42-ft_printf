/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:57:02 by lguillau          #+#    #+#             */
/*   Updated: 2021/11/24 14:05:48 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*cpy;

	tmp = *lst;
	while (tmp)
	{
		cpy = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = cpy;
	}
	*lst = NULL;
}
