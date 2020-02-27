/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:37:12 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"

void		save_link(t_link **linklst, t_link *new_link)
{
	t_link	**head;
	t_link	*pr;

	pr = *linklst;
	head = linklst;
	if (*head)
	{
		while (pr->next != NULL)
			pr = pr->next;
	}
	if (!*head)
	{
		*head = new_link;
		(*head)->next = NULL;
	}
	else
	{
		new_link->prev = pr;
		pr->next = new_link;
		pr->next->next = NULL;
	}
}
