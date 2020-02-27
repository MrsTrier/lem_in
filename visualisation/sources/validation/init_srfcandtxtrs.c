/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_srfcandtxtrs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:21:07 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"
#include "vis_errors.h"
#include "vis.h"

void			init_textures(t_vis_tools *vs)
{
	vs->render = SDL_CreateRenderer(vs->window, -1, 0);
	vs->room_texture = SDL_CreateTextureFromSurface(vs->render, vs->rooms);
	vs->backgrnd_txtr = SDL_CreateTextureFromSurface(vs->render, vs->backgrnd);
	vs->ant_txtr = SDL_CreateTextureFromSurface(vs->render, vs->ant);
}

bool			init_surface(t_vis_tools *vs)
{
	boolean_t	success;

	success = true;
	vs->backgrnd = IMG_Load("/Users/mcanhand/leeeeeeeeeeeemin/visualisation/sources/validation/space.jpg");
	vs->rooms = IMG_Load("/Users/mcanhand/leeeeeeeeeeeemin/visualisation/sources/validation/room.png");
	vs->ant = IMG_Load("/Users/mcanhand/leeeeeeeeeeeemin/visualisation/sources/validation/ant.png");
	if (vs->rooms == NULL)
		success = false;
	if (vs->backgrnd == NULL)
		success = false;
	init_textures(vs);
	return (success);
}
