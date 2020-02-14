
# include "validation.h"
# include "errors.h"
# include "visualization.h"

void	 init_textures(t_vis_tools *vs)
{
	vs->renderer = SDL_CreateRenderer(vs->window, -1, 0);
	vs->room_texture = SDL_CreateTextureFromSurface(vs->renderer, vs->rooms);
	vs->background_texture = SDL_CreateTextureFromSurface(vs->renderer, vs->background);
	vs->ant_texture = SDL_CreateTextureFromSurface(vs->renderer, vs->ant);
}

bool	init_surface(t_vis_tools *vs)
{
	boolean_t	success;

	success = true;
	vs->background = IMG_Load("/Users/mcanhand/Downloads/space.jpg");
	vs->rooms = IMG_Load("/Users/mcanhand/Downloads/room.png");
	vs->ant = IMG_Load("/Users/mcanhand/Downloads/ant.png");
	if (vs->rooms == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "03_event_driven_programming/x.bmp", SDL_GetError());
		success = false;
	}
	if (vs->background == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "03_event_driven_programming/x.bmp", SDL_GetError());
		success = false;
	}
	init_textures(vs);
	return success;
}
