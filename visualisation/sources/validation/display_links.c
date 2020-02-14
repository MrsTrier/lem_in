
# include "validation.h"
# include "errors.h"
# include "visualization.h"

void	display_links(t_input data, t_sizes *sizes, t_vis_tools *vs)
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;

	SDL_RenderCopy(vs->renderer, vs->background_texture, NULL, NULL);
	while (data.link != NULL)
	{
		start_x = data.link->start->x + sizes->room_width / 2;
		start_y = data.link->start->y + sizes->room_hight / 2;
		end_x = data.link->end->x + sizes->room_width / 2;
		end_y = data.link->end->y + sizes->room_hight / 2;
		SDL_SetRenderDrawColor(vs->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(vs->renderer, start_x, start_y, end_x, end_y);
		SDL_RenderDrawLine(vs->renderer, start_x + 1, start_y + 1, end_x + 1, end_y + 1);
		SDL_RenderDrawLine(vs->renderer, start_x + 2, start_y + 2, end_x + 2, end_y + 2);
		data.link = data.link->next;
	}
}