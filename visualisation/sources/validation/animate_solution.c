
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
		data.room = data.room->next;
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
			while (!quit)
			{
				display_links(data, &sizes, vs);
				display_rooms(data, &sizes, vs);
				display_ants(&data, i, vs, &sizes);
				display_titles(data, &sizes, vs);
				i++;
				SDL_RenderPresent(vs->renderer);
				SDL_Delay(1000 / 1);
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
						quit = 1;
				}
			}
		}
	}
}