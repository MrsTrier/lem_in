
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


void	suplus(t_input *data)
{
	t_ant		*pr_ant;
	t_iteration	*current;

	current = data->iteration;
	while (current)
	{
		pr_ant = current->ant;
		while (pr_ant)
		{
			pr_ant->move += 1;
			pr_ant= pr_ant->next;
		}
		current = current->next;
	}
}

void	display_ants(t_input *data, int index, t_vis_tools *vs, t_sizes *sizes)
{
	t_ant		*ant;
	t_iteration	*iter;
	t_ant		*pr_ant;
	t_ant		*prev_ant;
	int			x_shift;
	int			step_shift;
	int			down_shift;
	int			y_shift;
	t_iteration	*iter_prev;
	t_room		*st_room;
	int			pr_x;
	int			pr_y;

	step_shift = 0;
	down_shift = 0;
	x_shift = sizes->room_width / 2 - sizes->ant_w / 2;
	y_shift = sizes->room_hight / 2 - sizes->ant_h / 2;
	if (index > data->iter_num - 1)
		return ;
	if (!index && !vs->strt_displayed)
	{
		st_room = find_room(data, data->st_room);
		SDL_Rect ant_dstrect = {st_room->x + x_shift + step_shift, st_room->y + y_shift + down_shift,
		                        sizes->ant_w, sizes->ant_h};
		SDL_RenderCopy(vs->renderer, vs->ant_texture, NULL, &ant_dstrect);
		vs->strt_displayed = 1;
	}
	else
	{
		iter_prev = find_iter(data, index - 1);
		if (!iter_prev)
		{
			st_room = find_room(data, data->st_room);
			pr_x = st_room->x;
			pr_y = st_room->y;
		}
		iter = find_iter(data, index);
		pr_ant = iter->ant;
		while (iter->ant != NULL)
		{
			ant = iter->ant;
			if (iter_prev)
			{
				prev_ant = find_ant(iter_prev, ant->ant_index);
				pr_x = prev_ant->room->x;
				pr_y = prev_ant->room->y;
			}
			if (pr_x > ant->room->x)
				step_shift = -(((pr_x - ant->room->x) / 5) * ant->move);
			else
				step_shift = ((ant->room->x - pr_x) / 5) * ant->move;
			if (pr_y > ant->room->y)
				down_shift = -(((pr_y - ant->room->y) / 5) * ant->move);
			else
				down_shift = ((ant->room->y - pr_y) / 5) * ant->move;
			SDL_Rect ant_dstrect = {pr_x + x_shift + step_shift, pr_y + y_shift + down_shift,
			                        sizes->ant_w, sizes->ant_h};
			SDL_RenderCopy(vs->renderer, vs->ant_texture, NULL, &ant_dstrect);
			ant->type = ant->room->type;
			ant->move += 1;
			iter->ant = iter->ant->next;
		}
		iter->ant = pr_ant;
		suplus(data);
		//MOVE работает не правильно нужно move +1 сохранять!
	}
}
