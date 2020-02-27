/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_room.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:20:14 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"
#include "vis_errors.h"

t_room		*create_room(char *line, t_input *data, char ***objs)
{
	t_room	*room;

	*objs = ft_strsplit(line, ' ');
	room = (t_room *)malloc(sizeof(t_room));
	room->type = MIDDLE;
	room->next = NULL;
	room->name = ft_strdup((*objs)[0]);
	room->x = ft_atoi((*objs)[1]);
	room->y = ft_atoi((*objs)[2]);
	room->ant_number = 0;
	if (data->flag & START)
	{
		room->type = FIRST;
		data->flag &= ~START;
		data->start_room = 1;
		data->st_room = room->name;
		room->ant_number = data->ants_num;
	}
	if (data->flag & END)
	{
		room->type = LAST;
		data->nd_room = room->name;
	}
	return (room);
}

void		check_for_room(char *input, t_input *data, char ***objs)
{
	uint8_t	flag;
	t_room	*room;

	flag = data->flag;
	if ((flag & ANT) && !(flag & LINK))
	{
		room = create_room(input, data, objs);
		if (room_exists(data->room, room->name))
			error_found(ERR_ROOM_NAME_DUP);
		if (duplicated_coords(data->room, room->x, room->y))
			error_found(ERR_ROOM_COORDS_DUP);
		save_room(room, data);
		if (data->flag & END)
		{
			data->flag &= ~END;
			data->end_room = 1;
		}
		data->rooms_num += 1;
	}
	else
		error_found(ERR_INPUT);
}
