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
	SDL_FreeSurface(vs->textSurface);
	vs->textSurface = NULL;
	SDL_FreeSurface(vs->ndTextSurface);
	vs->ndTextSurface = NULL;
	SDL_FreeSurface(vs->stTextSurface);
	vs->stTextSurface = NULL;
	DESTROY_TXTR((vs->stText));
	DESTROY_TXTR((vs->text));
	DESTROY_TXTR(vs->stText);
	DESTROY_TXTR(vs->ndText);
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
		vs->textSurface = TTF_RenderText_Solid(vs->font,
								data.room->name, vs->textColor);
		vs->text = SDL_CreateTextureFromSurface(vs->render, vs->textSurface);
		text_width = vs->textSurface->w;
		text_height = vs->textSurface->h;
		dstrect = create_rect(data.room->x,
			data.room->y - (sizes->room_hight / 4), text_width, text_height);
		SDL_RenderCopy(vs->render, vs->text, NULL, &dstrect);
		print = ft_itoa(data.room->ant_number);
		vs->antnbSurface = TTF_RenderText_Solid(vs->font, print, vs->textColor);
		vs->antnb = SDL_CreateTextureFromSurface(vs->render, vs->antnbSurface);
		dstrect =
		create_rect(data.room->x + sizes->room_width, data.room->y
		+ sizes->room_hight, vs->antnbSurface->w, vs->antnbSurface->h);
		SDL_RenderCopy(vs->render, vs->stText, NULL, &(dstrect));
		free_mem_font(vs, print);
		data.room = data.room->next;
	}
}
