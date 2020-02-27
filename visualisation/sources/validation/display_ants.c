/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:20:24 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"
#include "vis_errors.h"
#include "vis.h"

void			calc_ants_num_inroom(t_ant *ant, t_input *data)
{
	t_room		*pr_room;
	t_room		*cur_room;
	char		*pr_name;
	char		*cur_name;

	pr_name = ant->cur_room->name;
	cur_name = ant->room->name;
	pr_room = find_room(data, pr_name);
	cur_room = find_room(data, cur_name);
	if (ant->move == 2)
		pr_room->ant_number--;
	if (ant->move == 15)
		cur_room->ant_number++;
}

SDL_Rect		calc_dstrect(t_ant *ant, t_sizes *sizes, t_vis_tools *vs)
{
	int			step_shift;
	int			down_shift;
	int			y_shift;
	int			pr_x;
	int			pr_y;

	pr_x = ant->cur_room->x;
	pr_y = ant->cur_room->y;
	y_shift = sizes->room_hight / 2 - sizes->ant_h / 2;
	if (pr_x > ant->room->x)
		step_shift = -(((pr_x - ant->room->x) / 14) * ant->move);
	else
		step_shift = ((ant->room->x - pr_x) / 14) * ant->move;
	if (pr_y > ant->room->y)
		down_shift = -(((pr_y - ant->room->y) / 14) * ant->move);
	else
		down_shift = ((ant->room->y - pr_y) / 14) * ant->move;
	(vs->ant_rect).y = pr_y + y_shift + down_shift;
	(vs->ant_rect).x = pr_x + (sizes->room_width / 2 - sizes->ant_w / 2)
			+ step_shift;
	(vs->ant_rect).w = sizes->ant_w;
	(vs->ant_rect).h = sizes->ant_h;
	ant->type = ant->room->type;
	ant->move += 1;
	return (vs->ant_rect);
}

void			display_staticants(t_input *data, t_sizes *sizes,
												t_vis_tools *vs)
{
	int			y_shift;
	int			x_shift;
	t_room		*current;

	current = data->room;
	y_shift = sizes->room_hight / 2 - sizes->ant_h / 2;
	x_shift = sizes->room_width / 2 - sizes->ant_w / 2;
	while (data->room != NULL)
	{
		if (data->room->ant_number)
		{
			(vs->ant_rect).x = data->room->x + x_shift;
			(vs->ant_rect).y = data->room->y + y_shift;
			(vs->ant_rect).w = sizes->ant_w;
			(vs->ant_rect).h = sizes->ant_h;
			SDL_RenderCopy(vs->render, vs->ant_txtr, NULL, &(vs->ant_rect));
		}
		data->room = data->room->next;
	}
	data->room = current;
}

void			display_ants(t_input *data, int index,
									t_vis_tools *vs, t_sizes *sizes)
{
	t_iteration	*iter;
	t_ant		*pr_ant;

	iter = find_iter(data, index);
	if (!index && !vs->strt_displayed++)
	{
		display_staticants(data, sizes, vs);
		return ;
	}
	if (iter != NULL)
	{
		pr_ant = iter->ant;
		while (iter->ant != NULL && index < data->iter_num)
		{
			vs->ant_rect = calc_dstrect(iter->ant, sizes, vs);
			calc_ants_num_inroom(iter->ant, data);
			if (iter->ant->move < 15)
				SDL_RenderCopy(vs->render, vs->ant_txtr, NULL, &(vs->ant_rect));
			iter->ant = iter->ant->next;
		}
		iter->ant = pr_ant;
	}
	display_staticants(data, sizes, vs);
}
