/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:19:35 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"
#include "vis_errors.h"
#include "vis.h"

void	rects_for_room(t_input data, t_sizes *sizes)
{
	while (data.room != NULL)
	{
		convert_coords(sizes, data.room);
		data.room = data.room->next;
	}
}

void	placerooms(t_input data, t_sizes *sizes)
{
	find_cels_num(sizes, data);
	printf("cels num calculated\n");
	calc_rooms_size(sizes);
	sizes->ant_w = sizes->room_width / 3.333;
	sizes->ant_h = sizes->ant_w / 0.7;
	rects_for_room(data, sizes);
}

void	track_events(t_vis_tools *vs, SDL_Event *e, bool *quit)
{
	while (SDL_PollEvent(&(*e)) != 0)
	{
		if ((*e).type == SDL_QUIT)
			*quit = true;
		else if ((*e).type == SDL_KEYDOWN)
		{
			if ((*e).key.keysym.sym == SDLK_LEFT && (vs->speed < 3600))
				vs->speed += 99;
			else if ((*e).key.keysym.sym == SDLK_RIGHT && /*(vs->speed > 5)*/ (vs->speed - 99 > 0))
				vs->speed -= 99;
		}
	}
}

void	animate_solution(t_input data, t_vis_tools *vs)
{
	bool		quit;
	SDL_Event	e;
	t_sizes		sizes;
	int			i;

	i = 0;
	if (!init(vs, &sizes))
		error_found(ERR_INIT_SDL, NULL);
	else
	{
		if (!init_surface(vs))
			error_found("ERROR: Failed to load media!\n", TTF_GetError());
		else
		{
			quit = false;
			printf("every thing inited\n");
			placerooms(data, &sizes);
			printf("plasing rooms\n");
			while (!quit)
			{
				display_objs(&data, &sizes, vs, &i);
				printf("displaying objs\n");

				SDL_RenderPresent(vs->render);
				SDL_Delay(vs->speed);
				track_events(vs, &e, &quit);
			}
		}
	}
}
