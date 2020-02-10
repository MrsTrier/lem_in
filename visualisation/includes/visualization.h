#ifndef VISUALIZATION_H
# define VISUALIZATION_H

#include <SDL.h>
#include <mach/machine.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
# include "validation.h"
# include "errors.h"


//
//
//SDL_Surface *gScreenSurface = NULL;
//
//SDL_Surface *background = NULL;
//SDL_Surface *rooms = NULL;
//SDL_Surface *ant = NULL;
//
//
//
//SDL_Renderer *renderer = NULL;
//SDL_Window *gWindow = NULL;
//
//SDL_Texture *room_texture = NULL;
//SDL_Texture *background_texture = NULL;
//SDL_Texture *ant_texture = NULL;

//typedef struct		s_vis_tools
//{
//	SDL_Window		*window;
//	SDL_Renderer	*renderer;
//	TTF_Font		*font;
//	SDL_Texture		*bg;
//	SDL_Rect		*bg_dims;
//	SDL_Texture		*lem_in;
//	SDL_Texture		*room_start_end;
//	SDL_Texture		*room_middle;
//	SDL_Texture		*ant;
////	SDL_Texture		*press_space;
////	SDL_Texture		*reload;
//	SDL_Texture		*next;
//	t_bool			welcome;
//	t_bool			close;
//	t_bool			ants_is_moving;
//	int				x_shift;
//	int				y_shift;
//}					t_vis_tools;


typedef struct		s_sizes
{
	int				bounds;
	int				room_hight;
	int				room_width;
	int				space_h;
	int				space_w;
	int				cels_num_h;
	int				cels_num_w;
	int 			screen_w;
	int 			screen_h;

}					t_sizes;


void	calc_rooms_size(int max_x, int max_y, t_sizes *sizes);

void	convert_coords(t_sizes *sizes, t_room *room);


#endif