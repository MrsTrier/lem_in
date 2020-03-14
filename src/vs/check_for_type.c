/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:20:19 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"
#include "vis_errors.h"

void	set_obj_flags(char *line, t_input *data)
{
	printf("              SOMEONE          !!!!!!\n");
	if (line[2] == 's')
	{
		data->start_room = -1;
		data->flag |= START;
		data->flag &= ~START_ROOM;
	}
	else if (line[2] == 'e')
	{
		data->end_room = -1;
		data->flag |= END;
		data->flag &= ~END_ROOM;
	}

}

void	check_for_type(char *input, t_input *data)
{
	if ((data->flag & START) == START &&
	    (data->flag & START_ROOM) != START_ROOM)
		error_found(ERR_START_END_ROOM, NULL);
	else if (((data->flag & END) == END) && ((data->flag & END_ROOM) != END_ROOM))
		error_found(ERR_START_END_ROOM, NULL);
	else
		set_obj_flags(input, data);
}
