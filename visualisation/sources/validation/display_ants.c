
# include "validation.h"
# include "errors.h"
# include "visualization.h"

void	display_ants(t_input *data, int index, t_vis_tools *vs)
{
	t_ant		*ant;
	t_iteration	*iter;

	iter = find_iter(data, index);
	while (iter->ant != NULL)
	{
		ant = iter->ant;
		SDL_Rect ant_dstrect = { ant->room->x + 80, ant->room->y + 50, 70, 100 };
		SDL_RenderCopy(vs->renderer, vs->ant_texture, NULL, &ant_dstrect);
		iter->ant = iter->ant->next;
	}
	SDL_RenderPresent(vs->renderer);
}
