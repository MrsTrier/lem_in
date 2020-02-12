
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

void		save_iteration(t_iteration **iter, t_iteration *new_iter)
{
	t_iteration	**head;
	t_iteration	*pr;

	pr = *iter;
	head = iter;
	if (*head)
	{
		while (pr->next != NULL)
		{
			pr = pr->next;
			new_iter->index += 1;
		}
	}
	if (!*head)
	{
		*head = new_iter;
		(*head)->next = NULL;
	}
	else
	{
		pr->next = new_iter;
		new_iter->index += 1;
        pr->next->next = NULL;
	}
}

void	push_new_ant(t_iteration **iter, t_ant *ant)
{
    t_iteration **head;
    t_iteration	*pr;

    pr = *iter;
    head = iter;
    if ((*head)->ant)
    {
        while (pr->ant->next != NULL)
            pr->ant = pr->ant->next;
    }
    if (!(*head)->ant)
    {
        (*head)->ant = ant;
        (*head)->ant->next = NULL;
    }
    else
    {
        pr->ant->next = ant;
        pr->ant->next->next = NULL;
    }
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
		ant->room = find_room(data, steps[1]);
		push_new_ant(&iter, ant);
        iter->ants_num += 1;
        i++;
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
		i++;
    }
	free_arr(objs);
	free(objs);
}
