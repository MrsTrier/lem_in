
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

void	check_for_strt_nd(t_input *data, int index, t_vis_tools *vs, t_sizes *sizes)
{
	t_room		*st_room;
	t_room		*nd_room;

	if (index > data->iter_num - 1)
	{
		nd_room = find_room(data, data->nd_room);
		SDL_Rect ant_dstrect = {nd_room->x + (sizes->room_width / 2 - sizes->ant_w / 2),
		                        nd_room->y + (sizes->room_hight / 2 - sizes->ant_h / 2),
		                        sizes->ant_w, sizes->ant_h};
		SDL_RenderCopy(vs->renderer, vs->ant_texture, NULL, &ant_dstrect);
	}
	else if (!index && !vs->strt_displayed)
	{
		st_room = find_room(data, data->st_room);
		SDL_Rect ant_dstrect = {st_room->x + (sizes->room_width / 2 - sizes->ant_w / 2),
		                        st_room->y + (sizes->room_hight / 2 - sizes->ant_h / 2),
		                        sizes->ant_w, sizes->ant_h};
		SDL_RenderCopy(vs->renderer, vs->ant_texture, NULL, &ant_dstrect);
		vs->strt_displayed = 1;
	}
}

void	if_frst_iter(int *pr_x, int *pr_y, t_input *data, t_iteration *iter_prev)
{
	t_room		*st_room;

	if (!iter_prev)
	{
		st_room = find_room(data, data->st_room);
		*pr_x = st_room->x;
		*pr_y = st_room->y;
	}
}

void	if_nofrst_iter(int *pr_x, int *pr_y, t_iteration *iter, t_iteration *iter_prev)
{
	t_ant		*prev_ant;

	if (iter_prev)
	{
		prev_ant = find_ant(iter_prev, iter->ant->ant_index);
		*pr_x = prev_ant->room->x;
		*pr_y = prev_ant->room->y;
	}
}

void	display_ants(t_input *data, int index, t_vis_tools *vs, t_sizes *sizes) {
	t_iteration *iter;
	t_ant *pr_ant;
	t_iteration *iter_prev;
	int pr_x;
	int pr_y;

	if ((index > data->iter_num - 1) || (!index && !vs->strt_displayed))
	{
		check_for_strt_nd(data, index, vs, sizes);
		return ;
	}
	else
	{
		iter_prev = find_iter(data, index - 1);
		if_frst_iter(&pr_x, &pr_y, data, iter_prev);
		iter = find_iter(data, index);
		pr_ant = iter->ant;
		while (iter->ant != NULL)
		{
			if_nofrst_iter(&pr_x, &pr_y, iter, iter_prev);
			vs->ant_dstrect = calc_dstrect(iter->ant, sizes, pr_x, pr_y);
			SDL_RenderCopy(vs->renderer, vs->ant_texture, NULL, &vs->ant_dstrect);
			iter->ant = iter->ant->next;
		}
		iter->ant = pr_ant;
	}
}
