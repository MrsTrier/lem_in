/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:21:41 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"
#include "vis_errors.h"

void		save_iteration(t_iteration **iter, t_iteration *new_iter)
{
	t_iteration	**head;
	t_iteration	*pr;

	pr = *iter;
	head = iter;
	if (*head)
	{
		while (pr->next != NULL)
		{
			pr = pr->next;
			new_iter->index += 1;
		}
	}
	if (!*head)
	{
		*head = new_iter;
		(*head)->next = NULL;
	}
	else
	{
		pr->next = new_iter;
		new_iter->index += 1;
		pr->next->next = NULL;
	}
}
