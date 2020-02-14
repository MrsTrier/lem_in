
# include "validation.h"
# include "errors.h"
# include "visualization.h"

void	display_ants(t_input *data, int index, t_vis_tools *vs, t_sizes * sizes)
{
	t_ant		*ant;
	t_iteration	*iter;
	t_iteration **pr_iter;
	int			x_shift;
	int			y_shift;

	x_shift = sizes->room_width / 2 - sizes->ant_w / 2;
	y_shift = sizes->room_hight / 2 - sizes->ant_h / 2;
	iter = find_iter(data, index);
//	pr_iter = &iter;
//	if (iter == NULL)
//	{
//
//	}
	while (iter && iter->ant != NULL)
	{
		ant = iter->ant;
		SDL_Rect ant_dstrect = { ant->room->x + x_shift, ant->room->y + y_shift, sizes->ant_w, sizes->ant_h };
		SDL_RenderCopy(vs->renderer, vs->ant_texture, NULL, &ant_dstrect);
		ant->type = ant->room->type;
		iter->ant = iter->ant->next;
	}
}
