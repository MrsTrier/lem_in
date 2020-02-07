/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:53:33 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/13 14:35:07 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	tmp = (*alst)->next;
	while (tmp)
	{
		ft_lstdelone(alst, del);
		*alst = tmp;
		tmp = tmp->next;
	}
	ft_lstdelone(alst, del);
	*alst = NULL;
}
