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
	if ((data->flag & START) == START)
	{
		room->type = FIRST;
		data->flag &= ~START;
		data->start_room = 1;
		data->st_room = room->name;
		room->ant_number = data->ants_num;
	}
	if ((data->flag & END) == END)
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
//	printf("check for room\n");
	if ((flag & LINK) != LINK)
		printf("there is no link\n");
	if (((flag & ANT) == ANT) && ((flag & LINK) != LINK))
	{
		room = create_room(input, data, objs);
		printf("room created %s\n", room->name);
		if (room_exists(data->room, room->name))
			error_found(ERR_ROOM_NAME_DUP, NULL);
		if (duplicated_coords(data->room, room->x, room->y))
			error_found(ERR_ROOM_COORDS_DUP, NULL);
		save_room(room, data);
		if ((flag & START) == START)
		{
			data->flag &= ~START;
			data->start_room = 1;
		}
		if ((flag & END) == END)
		{
			data->flag &= ~END;
			data->end_room = 1;
		}
		data->rooms_num += 1;
//		if ((flag & END) == END)
//			printf("\nflag END\n");
//		if ((flag & END_ROOM) == END_ROOM)
//			printf("\nflag END_ROOM\n");
//		if ((flag & START) == START)
//			printf("\nflag START\n");
//		if ((flag & START_ROOM) == START_ROOM)
//			printf("\nflag START\n");
	}
	else
		error_found(ERR_INPUT, NULL);
}
