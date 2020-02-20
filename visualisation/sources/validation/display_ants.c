
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

SDL_Rect	calc_dstrect(t_ant *ant, t_sizes *sizes, int pr_x, int pr_y)
{
	int			step_shift;
	int			down_shift;
	int			x_shift;
	int			y_shift;


	x_shift = sizes->room_width / 2 - sizes->ant_w / 2;
	y_shift = sizes->room_hight / 2 - sizes->ant_h / 2;
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
	ant->type = ant->room->type;
	ant->move += 1;
	return (ant_dstrect);
}

void	display_ants_atend(t_input *data, t_sizes *sizes, t_vis_tools *vs)
{
	t_room		*nd_room;

	if (data->atend)
	{
		nd_room = find_room(data, data->nd_room);
		SDL_Rect ant_dstrect = {nd_room->x + (sizes->room_width / 2 - sizes->ant_w / 2),
		                        nd_room->y + (sizes->room_hight / 2 - sizes->ant_h / 2),
		                        sizes->ant_w, sizes->ant_h};
		SDL_RenderCopy(vs->renderer, vs->ant_texture, NULL, &ant_dstrect);
	}
}

void	display_ants_onstart(t_input *data, t_sizes *sizes, t_vis_tools *vs)
{
	t_room		*st_room;

	if (data->onstart)
	{
		st_room = find_room(data, data->st_room);
		SDL_Rect ant_dstrect = {st_room->x + (sizes->room_width / 2 - sizes->ant_w / 2),
	                        st_room->y + (sizes->room_hight / 2 - sizes->ant_h / 2),
	                        sizes->ant_w, sizes->ant_h};
		SDL_RenderCopy(vs->renderer, vs->ant_texture, NULL, &ant_dstrect);
	}
}

void	display_ants(t_input *data, int index, t_vis_tools *vs, t_sizes *sizes)
{
	t_iteration *iter;
	t_ant *pr_ant;
	int pr_x;
	int pr_y;

	iter = find_iter(data, index);
	if (!index && !vs->strt_displayed++)
	{
		display_ants_onstart(data, sizes, vs);
		return ;
	}
	if (iter != NULL)
	{
		pr_ant = iter->ant;
		while (iter->ant != NULL && index < data->iter_num)
		{
			pr_x = iter->ant->cur_room->x;
			pr_y = iter->ant->cur_room->y;
			if (iter->ant->move == 1 && iter->ant->type == FIRST && iter->ant->room->type != FIRST)
				data->onstart--;
			vs->ant_dstrect = calc_dstrect(iter->ant, sizes, pr_x, pr_y);
			if (iter->ant->room->type == LAST && iter->ant->move == 6)
				data->atend++;
			SDL_RenderCopy(vs->renderer, vs->ant_texture, NULL, &vs->ant_dstrect);
			iter->ant = iter->ant->next;
		}
		iter->ant = pr_ant;
	}
	display_ants_onstart(data, sizes, vs);
	display_ants_atend(data, sizes, vs);
}
