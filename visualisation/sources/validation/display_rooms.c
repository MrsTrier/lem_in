# include "validation.h"
# include "errors.h"
# include "visualization.h"

void	display_rooms(t_input data, t_sizes *sizes, t_vis_tools *vs)
{
	while (data.room != NULL)
	{
		SDL_Rect room_dstrect = { data.room->x, data.room->y, sizes->room_width, sizes->room_hight};
		SDL_RenderCopy(vs->renderer, vs->room_texture, NULL, &room_dstrect);
		data.room = data.room->next;
	}
}
