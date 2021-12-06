/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:17:12 by lguillau          #+#    #+#             */
/*   Updated: 2021/11/24 14:44:03 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlist;
	t_list	*tmp;

	nlist = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!lst)
		{
			ft_lstclear(&nlist, del);
			nlist = NULL;
		}
		lst = lst->next;
		ft_lstadd_back(&nlist, tmp);
	}
	return (nlist);
}
