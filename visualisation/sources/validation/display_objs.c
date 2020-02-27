/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_objs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:20:28 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"
#include "vis_errors.h"
#include "vis.h"

void			zero_ant(t_input *data)
{
	t_ant		*pr_ant;
	t_iteration	*current;

	current = data->iteration;
	while (current)
	{
		pr_ant = current->ant;
		while (pr_ant)
		{
			pr_ant->move = 1;
			pr_ant = pr_ant->next;
		}
		current = current->next;
	}
}

void			display_links(t_input data, t_sizes *sizes, t_vis_tools *vs)
{
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;

	SDL_RenderCopy(vs->render, vs->backgrnd_txtr, NULL, NULL);
	while (data.link != NULL)
	{
		start_x = data.link->start->x + sizes->room_width / 2;
		start_y = data.link->start->y + sizes->room_hight / 2;
		end_x = data.link->end->x + sizes->room_width / 2;
		end_y = data.link->end->y + sizes->room_hight / 2;
		SDL_SetRenderDrawColor(vs->render, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(vs->render, start_x, start_y, end_x, end_y);
		SDL_RenderDrawLine(vs->render, start_x + 1, start_y + 1,
													end_x + 1, end_y + 1);
		SDL_RenderDrawLine(vs->render, start_x + 2, start_y + 2,
													end_x + 2, end_y + 2);
		data.link = data.link->next;
	}
}

void			display_rooms(t_input data, t_sizes *sizes, t_vis_tools *vs)
{
	SDL_Rect	room_dstrect;

	while (data.room != NULL)
	{
		room_dstrect.x = data.room->x;
		room_dstrect.y = data.room->y;
		room_dstrect.w = sizes->room_width;
		room_dstrect.h = sizes->room_hight;
		SDL_RenderCopy(vs->render, vs->room_texture, NULL, &room_dstrect);
		data.room = data.room->next;
	}
}

void			display_objs(t_input *data, t_sizes *sizes,
										t_vis_tools *vs, int *i)
{
	t_iteration *iter;

	display_links(*data, sizes, vs);
	display_rooms(*data, sizes, vs);
	display_ants(data, *i, vs, sizes);
	display_titles(*data, sizes, vs);
	iter = find_iter(data, *i);
	if (iter)
	{
		if (iter->ant->move == 15)
		{
			zero_ant(data);
			(*i)++;
		}
	}
}
