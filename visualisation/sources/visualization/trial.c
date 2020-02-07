# include "visualization.h"


//Screen dimension constants
const int SCREEN_WIDTH = 1940;
const int SCREEN_HEIGHT = 1080;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void	terminate();

SDL_Texture *room_texture = NULL;
SDL_Texture *background_texture = NULL;
SDL_Texture *ant_texture = NULL;

SDL_Renderer *renderer = NULL;
SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;

SDL_Surface *background = NULL;
SDL_Surface *rooms = NULL;
SDL_Surface *ant = NULL;


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

int main (int ac, char **av)
{
	bool		quit;
	SDL_Event	e;
	t_vis_tools	vs;

	if (!init())
		error_found(ERR_INIT_SDL);
	else
	{
		if (!loadMedia())
			printf( "Failed to load media!\n" );
		else
		{
			quit = 0;
			while (!quit)
			{
	            while (SDL_PollEvent(&e) != 0)
	                if (e.type == SDL_QUIT)
						quit = 1;
//	            vs.renderer;
				SDL_Rect room_dstrect = { 150, 105, 250, 200 };
				SDL_Rect ant_dstrect = { 150 + 80, 105 + 50, 70, 100 };
				SDL_RenderCopy(renderer, background_texture, NULL, NULL);

				SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
				SDL_RenderDrawLine(renderer, 620, 800, 300, 240);
				SDL_RenderDrawLine(renderer, 620 + 1, 800 + 1, 300 + 1, 240 + 1);
				SDL_RenderDrawLine(renderer, 620 + 2, 800 + 2, 300 + 2, 240 + 2);

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				SDL_RenderCopy(renderer, room_texture, NULL, &room_dstrect);
				SDL_RenderCopy(renderer, ant_texture, NULL, &ant_dstrect);
				SDL_RenderPresent(renderer);
			}
	    }
	 }
	 //Free resources and close SDL
	 terminate();

	 return 1;
}

//include_directories(~/Library/Frameworks/SDL2.framework/Headers)
//include_directories(~/Library/Frameworks/SDL2_image.framework/Headers)
//include_directories(~/Library/Frameworks/SDL2_ttf.framework/Headers)
//
//target_link_libraries(visualize_new "-framework SDL2")
//target_link_libraries(visualize_new "-framework SDL2_image")
//target_link_libraries(visualize_new "-framework SDL2_ttf")
//set_target_properties(visualize_new PROPERTIES LINK_FLAGS "-F /Users/$ENV{USER}/Library/Frameworks")