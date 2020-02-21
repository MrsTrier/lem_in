
# include "validation.h"
# include "errors.h"
# include <stdio.h>
#include <SDL_events.h>

# include "visualization.h"

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
	calc_rooms_size(sizes);
	calc_additional_metrics(sizes);
	rects_for_room(data, sizes);
}


void	free_mem_font(t_vis_tools *vs)
{
	SDL_FreeSurface(vs->textSurface);
	vs->textSurface = NULL;
	SDL_FreeSurface(vs->ndTextSurface);
	vs->ndTextSurface = NULL;
	SDL_FreeSurface(vs->stTextSurface);
	vs->stTextSurface = NULL;
	DESTROY_TXTR((vs->text));
	DESTROY_TXTR(vs->stText);
	DESTROY_TXTR(vs->ndText);
}
void	print_room_type(t_vis_tools *vs, t_sizes *sizes, int text_width, t_input data)
{
	int text_w;
	int text_h;

	vs->stTextSurface = TTF_RenderText_Solid(vs->font, "START", vs->textColor);
	vs->stText = SDL_CreateTextureFromSurface(vs->renderer, vs->stTextSurface);
	text_w = vs->stTextSurface->w;
	text_h = vs->stTextSurface->h;
	if (data.room->type == FIRST)
	{
		SDL_Rect renderstQuad = {data.room->x + text_width, data.room->y - (sizes->room_hight / 4), text_w, text_h};
		SDL_RenderCopy(vs->renderer, vs->stText, NULL, &renderstQuad);
	}
	vs->ndTextSurface = TTF_RenderText_Solid(vs->font, "END", vs->textColor);
	vs->ndText = SDL_CreateTextureFromSurface(vs->renderer, vs->ndTextSurface);
	text_w = vs->ndTextSurface->w;
	text_h = vs->ndTextSurface->h;
	if (data.room->type == LAST)
	{
		SDL_Rect renderndQuad = { data.room->x + text_width, data.room->y - (sizes->room_hight / 4), text_w, text_h };
		SDL_RenderCopy(vs->renderer, vs->ndText, NULL, &renderndQuad);
	}
}

void	display_titles(t_input data, t_sizes *sizes, t_vis_tools *vs)
{
	int text_width;
	int text_height;

	while (data.room != NULL)
	{
		vs->textSurface = TTF_RenderText_Solid(vs->font, data.room->name, vs->textColor);
		vs->text = SDL_CreateTextureFromSurface(vs->renderer, vs->textSurface);
		text_width = vs->textSurface->w;
		text_height = vs->textSurface->h;
		SDL_Rect renderQuad = { data.room->x, data.room->y - (sizes->room_hight / 4), text_width, text_height };
		SDL_RenderCopy(vs->renderer, vs->text, NULL, &renderQuad);
		print_room_type(vs, sizes, text_width, data);
		free_mem_font(vs);
		data.room = data.room->next;
	}
}

void	zero_ant(t_input *data)
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
			pr_ant= pr_ant->next;
		}
		current = current->next;
	}
}

void	display_objs(t_input *data, t_sizes *sizes, t_vis_tools *vs, int *i)
{
	t_iteration *iter;

	display_links(*data, sizes, vs);
	display_rooms(*data, sizes, vs);
	display_ants(data, *i, vs, sizes);
	display_titles(*data, sizes, vs);
	iter = find_iter(data, *i);
	if (iter)
	{
		if (iter->ant->move == 6) {
			zero_ant(data);
			(*i)++;
		}
	}
}

void	animate_solution(t_input data, t_vis_tools *vs)
{
	bool		quit;
	SDL_Event	e;
	t_sizes		sizes;
	int			i;
	const Uint8 *keystates;

	i = 0;
	if (!init(vs, &sizes))
		error_found(ERR_INIT_SDL);
	else
	{
		keystates = SDL_GetKeyboardState(NULL);
		if (!init_surface(vs))
			printf("Failed to load media!\n");
		else
		{
			quit = 0;
			placerooms(data, &sizes);
			while (!quit) {
				display_objs(&data, &sizes, vs, &i);
				SDL_RenderPresent(vs->renderer);
				SDL_Delay(vs->speed);
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
						quit = 1;
					if (e.type == SDL_KEYDOWN)
					{
						if (e.key.keysym.sym == SDLK_LEFT)
							vs->speed -= 100;
						if (e.key.keysym.sym == SDLK_RIGHT)
							vs->speed -= 100;
					}
//					if (keystates[SDL_GetScancodeFromKey(SDLK_RIGHT)])
//						vs->speed += 100;
//					if (keystates[SDL_GetScancodeFromKey(SDLK_LEFT)])
//						vs->speed -= 100;
				}
			}
		}
	}
}
