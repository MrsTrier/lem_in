
# include "validation.h"
# include "errors.h"
# include <stdio.h>
# include "visualization.h"

bool	init_sdl_images()
{
	boolean_t success;

	success = true;
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		printf( "Could not initialize SDL_image! SDL_Error: %s\n", IMG_GetError() );
		success = false;
	}
	return success;
}

bool	init(t_vis_tools *vs, t_sizes *sizes)
{
	bool	success;

    sizes->screen_h = 1080;
    sizes->screen_w = 1940;
	success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		vs->window = SDL_CreateWindow("Lem-in", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                      sizes->screen_w, sizes->screen_h, SDL_WINDOW_SHOWN);
		if (vs->window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
	}
	if (!init_sdl_images())
		success = false;
	return success;
}
