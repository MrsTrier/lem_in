#ifndef VISUALIZATION_H
# define VISUALIZATION_H
//#include <SDL2/SDL.h>
//#include <mach/machine.h>
//#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_ttf.h>

# define DESTROY_TXTR(X)	if (X) SDL_DestroyTexture(X);

#include <SDL.h>
#include <mach/machine.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
# include "validation.h"
# include "errors.h"



typedef struct		s_vis_tools
{
	int				speed;
	SDL_Color		textColor;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Surface		*background;
	SDL_Surface		*rooms;
	SDL_Surface		*ant;
	SDL_Surface		*textSurface;
	SDL_Texture		*ant_texture;
    SDL_Texture		*room_texture;
	SDL_Texture		*background_texture;
	TTF_Font		*font;
	SDL_Rect		ant_dstrect;
	SDL_Texture		*room_start_end;
	SDL_Texture		*room_middle;
	SDL_Texture		*next;
	SDL_Texture		*text;
	SDL_Surface		*stTextSurface;
	SDL_Texture		*stText;
	SDL_Surface		*ndTextSurface;
	SDL_Texture		*ndText;
	int				strt_displayed;
}					t_vis_tools;


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
	int				max_y;
	int				max_x;
	int				min_y;
	int				min_x;
	int				ant_w;
	int				ant_h;
}					t_sizes;


void				calc_rooms_size(t_sizes *sizes);

void				convert_coords(t_sizes *sizes, t_room *room);

void				display_links(t_input data, t_sizes *sizes, t_vis_tools *vs);

void				display_ants(t_input *data, int index, t_vis_tools *vs, t_sizes *sizes);

void				display_rooms(t_input data, t_sizes *sizes, t_vis_tools *vs);

t_iteration			*find_iter(t_input *input, int index);

t_ant				*find_ant(t_iteration *iteration, int index);

void				find_cels_num(t_sizes *sizes, t_input data);

bool				init(t_vis_tools *vs, t_sizes *sizes);

bool				init_surface(t_vis_tools *vs);

void				animate_solution(t_input data, t_vis_tools *vs);

void				calc_additional_metrics(t_sizes *sizes);

void				save_iteration(t_iteration **iter, t_iteration *new_iter);


#endif