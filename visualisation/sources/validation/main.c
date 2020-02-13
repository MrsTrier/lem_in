
# include "validation.h"
# include "errors.h"
# include <stdio.h>
# include "visualization.h"

const int SCREEN_WIDTH = 1940;
const int SCREEN_HEIGHT = 1080;

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
	sizes->screen_h = 1080;
	sizes->screen_w = 1940;
	find_cels_num(sizes, data);
	calc_rooms_size(sizes);
	rects_for_room(data, sizes);
}

void	terminate(t_vis_tools *vs)
{
	SDL_FreeSurface(vs->background);
	vs->background = NULL;
	SDL_FreeSurface(vs->rooms);
	vs->rooms = NULL;
    SDL_DestroyTexture(vs->ant_texture);
	SDL_DestroyTexture(vs->room_texture);
	SDL_DestroyTexture(vs->background_texture);
	SDL_DestroyRenderer(vs->renderer);
	SDL_DestroyWindow(vs->window);
	vs->window = NULL;
	SDL_Quit();
}

void	animate_sollution(t_input data)
{
	bool		quit;
	SDL_Event	e;
	t_sizes		sizes;
	int			i;
	t_vis_tools	vs;

	i = 0;
	if (!init(&vs))
		error_found(ERR_INIT_SDL);
	else
	{
		if (!init_surface(&vs))
			printf("Failed to load media!\n");
		else
		{
			quit = 0;
			placerooms(data, &sizes);
			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
					if (e.type == SDL_QUIT)
						quit = 1;
				display_links(data, &sizes);
				display_rooms(data, &sizes);
				display_ants(&data, i);
				SDL_Delay(1000 / 60);
				i++;
			}
		}
	}
	terminate();
}

int			main(void)
{
	char *res;
	t_input		data;

	read_validate(&res, &data);
	animate_sollution(data);

	free_room(&data);
	free_links(&data);
	return (0);
}