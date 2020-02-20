
# include "visualization.h"
# include "validation.h"
# include "errors.h"
# include <stdio.h>


void	check_params(char *ant_room, t_input *data)
{
	char		**objs;

	objs = ft_strsplit(ant_room, '-');
	if (!is_int(objs[0]))
		error_found(ERR_INPUT);
	if (ft_atoi(objs[0]) > data->ants_num)
		error_found(ERR_INPUT);
	if (!room_exists(data->room, objs[1]))
		error_found(ERR_INPUT);
	free_arr(objs);
	free(objs);
}

void	push_new_ant(t_ant **ant, t_ant *new_ant)
{
    t_ant **head;
    t_ant *pr;

    pr = *ant;
    head = ant;
    if ((*head))
    {
        while (pr->next != NULL)
	        pr = pr->next;
    }
    if (!(*head))
    {
        (*head) = new_ant;
        (*head)->next = NULL;
    }
    else
    {
	    pr->next = new_ant;
	    pr->next->next = NULL;
    }
}

t_room	*cur_room(t_input *data, t_ant *ant)
{
	t_iteration *iter;
	t_room		*res_room;
	t_ant		*prev_ant;
	int			i;

	i = 0;
	prev_ant = NULL;
	res_room = NULL;
	while (i < data->iter_num)
	{
		iter = find_iter(data, i);
		if ((prev_ant = find_ant(iter, ant->ant_index)) != NULL)
			res_room = prev_ant->room;
		else if (res_room == NULL)
			res_room = find_room(data, data->st_room);
		i++;
	}
	return (res_room);
}

t_iteration		*create_iteration(t_input *data, char *line)
{
	t_iteration *iter;
	char		**objs;
	char		**steps;
	t_ant		*ant;
    int			i;

    i = 0;
	objs = ft_strsplit(line, ' ');
	iter = (t_iteration *)malloc(sizeof(t_iteration));
    iter->index = 0;
    iter->ant = NULL;
	iter->ants_num = 0;
	while (objs[i] != NULL)
	{
		steps = ft_strsplit(objs[i], '-');
		ant = (t_ant *)malloc(sizeof(t_ant));
		ant->ant_index = ft_atoi(steps[0] + 1);
		ant->next = NULL;
		ant->room = find_room(data, steps[1]);
		ant->move = 1;
		if (data->iteration)
			ant->cur_room = cur_room(data, ant);
		else
			ant->cur_room = find_room(data, data->st_room);
		if (ant->cur_room->name == data->st_room)
			ant->type = FIRST;
		else
			ant->type = MIDDLE;
		push_new_ant(&(iter->ant), ant);
        iter->ants_num += 1;
        i++;
		free_arr(steps);
		free(steps);
	}
    iter->next = NULL;
	free_arr(objs);
	free(objs);
	return (iter);
}

void	is_res_right(char *res, t_input *data)
{
	char		**objs;
	char		*ant_room;
	int 		i;

	i = 0;
	objs = ft_strsplit(res, ' ');
	while (objs[i] != NULL)
	{
		ant_room = (objs[i] + 1);
		if (objs[i][0] != 'L')
			error_found(ERR_INPUT);
		check_params(ant_room, data);
		i++;
	}
	free_arr(objs);
	free(objs);
}


void	validate_result(char *res, t_input *data)
{
	char		**objs;
	int 		i;
	t_iteration	*iter;

	i = 0;
	objs = ft_strsplit(res, '\n');
	while (objs[i] != NULL)
	{
		is_res_right(objs[i], data);
		iter = create_iteration(data, objs[i]);
		save_iteration(&(data->iteration), iter);
		data->iter_num += 1;
		i++;
    }
	data->onstart = data->ants_num;
	data->atend = 0;
	free_arr(objs);
	free(objs);
}
