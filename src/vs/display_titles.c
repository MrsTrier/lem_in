/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_titles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:20:32 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"
#include "vis_errors.h"
#include "vis.h"

void			free_mem_font(t_vis_tools *vs, char *print)
{
	free(print);
	SDL_FreeSurface(vs->text_surface);
	vs->text_surface = NULL;
	SDL_FreeSurface(vs->antnb_srfc);
	vs->antnb_srfc = NULL;
	DESTROY_TXTR(vs->antnb);
	DESTROY_TXTR(vs->text);
}

SDL_Rect		create_rect(int x, int y, int text_w, int text_h)
{
	SDL_Rect	dstrect;

	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = text_w;
	dstrect.h = text_h;
	return (dstrect);
}

void			display_titles(t_input data, t_sizes *sizes, t_vis_tools *vs)
{
	int			text_width;
	int			text_height;
	SDL_Rect	dstrect;
	char		*print;

	while (data.room != NULL)
	{
		vs->text_surface = TTF_RenderText_Solid(vs->font,
								data.room->name, vs->text_color);
		vs->text = SDL_CreateTextureFromSurface(vs->render, vs->text_surface);
		text_width = vs->text_surface->w;
		text_height = vs->text_surface->h;
		dstrect = create_rect(data.room->x,
			data.room->y - (sizes->room_hight / 4), text_width, text_height);
		SDL_RenderCopy(vs->render, vs->text, NULL, &dstrect);
		print = ft_itoa(data.room->ant_number);
		vs->antnb_srfc = TTF_RenderText_Solid(vs->font, print, vs->text_color);
		vs->antnb = SDL_CreateTextureFromSurface(vs->render, vs->antnb_srfc);
		dstrect =
		create_rect(data.room->x + sizes->room_width, data.room->y
		+ sizes->room_hight, vs->antnb_srfc->w, vs->antnb_srfc->h);
		SDL_RenderCopy(vs->render, vs->antnb, NULL, &(dstrect));
		free_mem_font(vs, print);
		data.room = data.room->next;
	}
}
