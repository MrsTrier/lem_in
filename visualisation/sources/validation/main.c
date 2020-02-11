
# include "validation.h"
# include "errors.h"
# include <stdio.h>
# include "visualization.h"


const int SCREEN_WIDTH = 1940;
const int SCREEN_HEIGHT = 1080;

SDL_Texture *room_texture = NULL;
SDL_Texture *background_texture = NULL;
SDL_Texture *ant_texture = NULL;

SDL_Renderer *renderer = NULL;
SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;

SDL_Surface *background = NULL;
SDL_Surface *rooms = NULL;
SDL_Surface *ant = NULL;

int		find_max(t_input data, char c)
{
	int	max;
	int	next;

	max = (c == 'x') ? data.room->x : data.room->y;
	while (data.room->next != NULL)
	{
		next = (c == 'x') ? data.room->next->x : data.room->next->y;
		if (max < next)
			max = next;
		data.room = data.room->next;
	}
	return (max);
}

int		find_min(t_input data, char c)
{
	int	min;
	int	next;

	min = (c == 'x') ? data.room->x : data.room->y;
	while (data.room->next != NULL)
	{
		next = (c == 'x') ? data.room->next->x : data.room->next->y;
		if (next < min)
			min = next;
		data.room = data.room->next;
	}
	return (min);
}


void	find_cels_num(t_sizes *sizes, t_input data)
{
	sizes->max_y = find_max(data, 'y');
	sizes->max_x = find_max(data, 'x');
	sizes->min_y = find_min(data, 'y');
	sizes->min_x = find_min(data, 'x');
	sizes->cels_num_w = (sizes->max_x < 0) ? -(sizes->max_x - (-1 * sizes->min_x)) : sizes->max_x - sizes->min_x;
	sizes->cels_num_h = (sizes->max_y < 0) ? -(sizes->max_y - (-1 * sizes->min_y)) : sizes->max_y - sizes->min_y;
	printf("\nMIN X ---> %d\nMIN Y ---> %d\n", sizes->min_x, sizes->min_y);
	printf("\nMAX X ---> %d\nMAX Y ---> %d\n", sizes->max_x, sizes->max_y);

	printf("\nCels num in horizontal ---> %d\n", sizes->cels_num_w);
	printf("\nCels num in vertical ---> %d\n", sizes->cels_num_h);

}

void	rects_for_room(t_input data, t_sizes *sizes)
{
	while (data.room != NULL)
	{
		convert_coords(sizes, data.room);
		data.room = data.room->next;
	}
}

void	display_links(t_input data, t_sizes *sizes)
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;

	SDL_RenderCopy(renderer, background_texture, NULL, NULL);
	while (data.link != NULL)
	{
		start_x = data.link->start->x + sizes->room_width / 2;
		start_y = data.link->start->y + sizes->room_hight / 2;
		end_x = data.link->end->x + sizes->room_width / 2;
		end_y = data.link->end->y + sizes->room_hight / 2;
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(renderer, start_x, start_y, end_x, end_y);
		SDL_RenderDrawLine(renderer, start_x + 1, start_y + 1, end_x + 1, end_y + 1);
		SDL_RenderDrawLine(renderer, start_x + 2, start_y + 2, end_x + 2, end_y + 2);
		data.link = data.link->next;
	}
}

void	display_rooms(t_input data, t_sizes *sizes)
{
    while (data.room != NULL)
	{
		SDL_Rect room_dstrect = { data.room->x, data.room->y, sizes->room_width, sizes->room_hight};
		SDL_RenderCopy(renderer, room_texture, NULL, &room_dstrect);
		data.room = data.room->next;
	}
//	SDL_Rect ant_dstrect = { 150 + 80, 105 + 50, 70, 100 };
//	SDL_RenderCopy(renderer, ant_texture, NULL, &ant_dstrect);
	SDL_RenderPresent(renderer);

}

void	placerooms(t_input data, t_sizes *sizes)
{
	sizes->screen_h = 1080;
	sizes->screen_w = 1940;
	find_cels_num(sizes, data);
	calc_rooms_size(sizes);
	rects_for_room(data, sizes);
}

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

bool	init()
{
	bool	success;

	success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("Lem-in", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
								   SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
	}
	if (!init_sdl_images())
		success = false;
	return success;
}

void     init_textures(void)
{
	renderer = SDL_CreateRenderer(gWindow, -1, 0);
	room_texture = SDL_CreateTextureFromSurface(renderer, rooms);
	background_texture = SDL_CreateTextureFromSurface(renderer, background);
	ant_texture = SDL_CreateTextureFromSurface(renderer, ant);
}

bool	loadMedia()
{
	boolean_t	success;

	success = true;
	background = IMG_Load("/Users/mcanhand/Downloads/space.jpg");
	rooms = IMG_Load("/Users/mcanhand/Downloads/room.png");
	ant = IMG_Load("/Users/mcanhand/Downloads/ant.png");
	if (rooms == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "03_event_driven_programming/x.bmp", SDL_GetError());
		success = false;
	}
	if (background == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "03_event_driven_programming/x.bmp", SDL_GetError());
		success = false;
	}
	init_textures();
	return success;
}

void	terminate()
{
	SDL_FreeSurface(background);
	background = NULL;
	SDL_FreeSurface(rooms);
	rooms = NULL;
	SDL_DestroyTexture(room_texture);
	SDL_DestroyTexture(ant_texture);
	SDL_DestroyTexture(background_texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}

void	animate_sollution(t_input data)
{
	bool		quit;
	SDL_Event	e;
	t_sizes	sizes;
//	t_vis_tools	vs;

	if (!init())
		error_found(ERR_INIT_SDL);
	else
	{
		if (!loadMedia())
			printf( "Failed to load media!\n" );
		else
		{
			quit = 0;
			placerooms(data, &sizes);
			while (!quit)
			{
	            while (SDL_PollEvent(&e) != 0)
                {
	            	if (e.type == SDL_QUIT)
					quit = 1;
                }
	            display_links(data, &sizes);
				display_rooms(data, &sizes);
				display_ants(data, &sizes);
                SDL_Delay(1000 / 60);

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