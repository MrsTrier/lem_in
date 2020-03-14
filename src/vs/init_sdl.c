/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:20:57 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"
#include "vis_errors.h"
#include "vis.h"

bool	init_sdl_images(void)
{
	boolean_t success;

	success = true;
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		success = false;
	return (success);
}

bool	init_font(t_vis_tools *vs)
{
	bool	success;

	success = false;
	if (TTF_Init() == -1)
		error_found("TTF_Init: ", TTF_GetError());
	else
	{
		vs->font = TTF_OpenFont("src/vs/font.ttf", 16);
		if (!vs->font)
			error_found("TTF_OpenFont: ", TTF_GetError());
		else
			success = true;
	}
	return (success);
}

bool	init(t_vis_tools *vs, t_sizes *sizes)
{
	bool	success;

	sizes->screen_h = 1080;
	sizes->screen_w = 1940;
	success = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		success = false;
	else
	{
		vs->window = SDL_CreateWindow("Lem-in", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, sizes->screen_w, sizes->screen_h,
			SDL_WINDOW_SHOWN);
		if (vs->window == NULL)
			success = false;
	}
	if (!init_sdl_images())
		success = false;
	if (!init_font(vs))
		success = false;
	return (success);
}
