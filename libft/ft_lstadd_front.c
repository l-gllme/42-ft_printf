/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:48:09 by lguillau          #+#    #+#             */
/*   Updated: 2021/11/18 23:14:43 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (*alst)
	{
		tmp = new;
		tmp->next = *alst;
		*alst = tmp;
	}
	else
	{
		*alst = new;
		new->next = NULL;
	}
}
