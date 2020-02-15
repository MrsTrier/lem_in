
# include "validation.h"
# include "errors.h"
# include "visualization.h"

t_ant		*find_ant(t_iteration *iteration, int index)
{
	t_ant	*current;

	current = iteration->ant;
	while (current)
	{
		if (current->ant_index == index)
			return (current);
		current = current->next;
	}
	return (NULL);
}


void	display_ants(t_input *data, int index, t_vis_tools *vs, t_sizes *sizes)
{
	t_ant		*ant;
	t_iteration	*iter;
	t_ant		*pr_ant;
	int			x_shift;
	int			y_shift;
	t_iteration	*iter_prev;

	x_shift = sizes->room_width / 2 - sizes->ant_w / 2;
	y_shift = sizes->room_hight / 2 - sizes->ant_h / 2;
	if (index > data->iter_num - 1)
		return ;
	iter_prev = find_iter(data, index - 1);
	iter = find_iter(data, index);
	pr_ant = iter->ant;
	while (iter->ant != NULL)
	{
		ant = iter->ant;
		pr_ant = find_ant(iter_prev, ant->ant_index);
		if (pr_ant->room->x > ant->room->x)
			x_shift -= pr_ant->room->x - ant->room->x / sizes->move;
		SDL_Rect ant_dstrect = { ant->room->x + x_shift, ant->room->y + y_shift, sizes->ant_w, sizes->ant_h };
		SDL_RenderCopy(vs->renderer, vs->ant_texture, NULL, &ant_dstrect);
		ant->type = ant->room->type;
		iter->ant = iter->ant->next;
	}
	iter->ant = pr_ant;
}
