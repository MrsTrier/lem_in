/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:37:26 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/04 12:37:28 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "validation.h"
# include "errors.h"
# include <stdio.h>

void push_new_room(t_room **roomlst, t_room *room)
{
	t_room **head;
	t_room	*pr;

	pr = *roomlst;
	head = roomlst;
	if (*head)
	{
		while (pr->next != NULL)
			pr = pr->next;
	}
	if (!*head)
	{
		*head = room;
		(*head)->next = NULL;
	}
	else
	{
		pr->next = room;
		pr->next->next = NULL;
	}
}

void	save_room(t_room *room, t_input *input)
{

	if (!(input->flag & ROOMS))
		input->flag |= ROOMS;
	if (input->flag & START)
		input->flag |= START_ROOM;
	if (input->flag & END)
		input->flag |= END_ROOM;
	push_new_room(&(input->room), room);
	printf("=== I saved room with name %s!!! ===\n", room->name);
	printf("=== Pointer is now on room %s!!! ===\n", (input->room)->name);
}
