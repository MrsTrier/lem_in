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
	vs->backgrnd = IMG_Load("src/vs/space.jpg");
	vs->rooms = IMG_Load("src/vs/room.png");
	vs->ant = IMG_Load("src/vs/ant.png");
	if (vs->rooms == NULL || vs->backgrnd == NULL || vs->ant == NULL)
		success = false;
	init_textures(vs);
	return (success);
}
