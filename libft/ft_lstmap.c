/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:43:14 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/10 13:11:56 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *elem;

	elem = NULL;
	if (lst)
	{
		elem = f(lst);
		if (elem)
			elem->next = ft_lstmap(lst->next, f);
	}
	return (elem);
}
