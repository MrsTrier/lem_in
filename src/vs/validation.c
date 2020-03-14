/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:37:34 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"
#include "vis_errors.h"

void	is_input_corect(t_input *input)
{
	printf("input->start_room %d, input->end_room %d\n", input->start_room, input->end_room);
	if ((input->start_room < 0) || (input->end_room < 0))
		error_found(ERR_START_END_ROOM, NULL);
	if ((input->flag & LINK) != LINK)
		error_found(ERR_NO_LINKS, NULL);
}

bool	room_exists(t_room *roomlst, char *name)
{
	if (roomlst)
	{
		while (roomlst->next != NULL)
		{
			if (!(ft_strcmp(roomlst->name, name)))
				return (true);
			roomlst = roomlst->next;
		}
		if (!(ft_strcmp(roomlst->name, name)))
			return (true);
	}
	return (false);
}

bool	duplicated_coords(t_room *roomlst, int x, int y)
{
	if (roomlst)
	{
		while (roomlst->next != NULL)
		{
			if ((roomlst->x == x) && (roomlst->y == y))
				return (true);
			roomlst = roomlst->next;
		}
		if ((roomlst->x == x) && (roomlst->y == y))
			return (true);
	}
	return (false);
}
