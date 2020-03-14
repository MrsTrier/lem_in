/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:21:23 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"
#include "vis_errors.h"
#include "vis.h"
#include <fcntl.h>

t_vis_tools		*create_vs(void)
{
	t_vis_tools	*vs;

	if (!(vs = (t_vis_tools *)ft_memalloc(sizeof(t_vis_tools))))
		error_found(ERR_VS_INIT, NULL);
	vs->window = NULL;
	vs->render = NULL;
	vs->font = NULL;
	vs->room_start_end = NULL;
	vs->room_middle = NULL;
	vs->ant = NULL;
	vs->next = NULL;
	vs->strt_displayed = 0;
	vs->text_color.r = 225;
	vs->text_color.g = 225;
	vs->text_color.b = 225;
	vs->text_color.a = 0;
	vs->speed = 500;
	return (vs);
}

void			free_surface(t_vis_tools *vs)
{
	SDL_FreeSurface(vs->backgrnd);
	vs->backgrnd = NULL;
	SDL_FreeSurface(vs->rooms);
	vs->rooms = NULL;
	SDL_FreeSurface(vs->ant);
	vs->ant = NULL;
}

void			free_vs(t_vis_tools **vs)
{
	if (vs && *vs)
	{
		free_surface(*vs);
		DESTROY_TXTR((*vs)->next);
		DESTROY_TXTR((*vs)->ant_txtr);
		DESTROY_TXTR((*vs)->backgrnd_txtr);
		DESTROY_TXTR((*vs)->room_texture);
		DESTROY_TXTR((*vs)->room_middle);
		DESTROY_TXTR((*vs)->room_start_end);
		TTF_CloseFont((*vs)->font);
		if ((*vs)->render)
			SDL_DestroyRenderer((*vs)->render);
		if ((*vs)->window)
			SDL_DestroyWindow((*vs)->window);
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
		free((*vs));
		(*vs) = NULL;
	}
}

//int				main(void)
int				main(int ac, char **av)

{
	char		*res;
	t_input		data;
	t_vis_tools	*vs;
	int			fd;

	fd = open(av[1], O_RDONLY);
	if (ac == 2)
	{
		vs = create_vs();
//		read_validate(&res, &data);
		read_validate(&res, &data, fd);
		printf("Animation\n");
		animate_solution(data, vs);
//		free_vs(&vs);
//		free_room(&data);
//		free_links(&data);
//		free_iter(&data);
	}
	exit (0);
}
