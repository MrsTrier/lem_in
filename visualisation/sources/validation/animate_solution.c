
# include "validation.h"
# include "errors.h"
# include <stdio.h>
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

void	display_titles(t_input data, t_sizes *sizes, t_vis_tools *vs)
{
	SDL_Color textColor = { 255, 255, 255, 0 };
	vs->font = TTF_OpenFont("/Users/mcanhand/Downloads/oswald/font.ttf", 16);
	if(!vs->font) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		// handle error
	}
	while (data.room != NULL)
	{
		vs->textSurface = TTF_RenderText_Solid(vs->font, data.room->name, textColor);
		vs->text = SDL_CreateTextureFromSurface(vs->renderer, vs->textSurface);
		int text_width = vs->textSurface->w;
		int text_height = vs->textSurface->h;
		SDL_Rect renderQuad = { data.room->x, data.room->y - (sizes->room_hight / 4), text_width, text_height };
		SDL_RenderCopy(vs->renderer, vs->text, NULL, &renderQuad);
		SDL_Surface *stTextSurface = TTF_RenderText_Solid(vs->font, "START", textColor);
		struct SDL_Texture *stText = SDL_CreateTextureFromSurface(vs->renderer, stTextSurface);
		int text_w = stTextSurface->w;
		int text_h = stTextSurface->h;
		SDL_Surface *ndTextSurface = TTF_RenderText_Solid(vs->font, "END", textColor);
		struct SDL_Texture *ndText = SDL_CreateTextureFromSurface(vs->renderer, ndTextSurface);
		int endtext_w = ndTextSurface->w;
		int endtext_h = ndTextSurface->h;
		if (data.room->type == FIRST)
		{
			SDL_Rect renderstQuad = {data.room->x + text_width, data.room->y - (sizes->room_hight / 4), text_w, text_h};
			SDL_RenderCopy(vs->renderer, stText, NULL, &renderstQuad);
		}
		if (data.room->type == LAST)
		{
			SDL_Rect renderndQuad = { data.room->x + text_width, data.room->y - (sizes->room_hight / 4), endtext_w, endtext_h };
			SDL_RenderCopy(vs->renderer, ndText, NULL, &renderndQuad);
		}
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

	i = 0;
	if (!init(vs, &sizes))
		error_found(ERR_INIT_SDL);
	else
	{
		if (!init_surface(vs))
			printf("Failed to load media!\n");
		else
		{
			quit = 0;
			placerooms(data, &sizes);
			while (!quit) {
				display_objs(&data, &sizes, vs, &i);
				SDL_RenderPresent(vs->renderer);
				SDL_Delay(1000 / 3);
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
						quit = 1;
				}
			}
		}
	}
}
