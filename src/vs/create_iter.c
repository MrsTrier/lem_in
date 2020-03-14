/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:35:41 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/26 11:35:44 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"
#include "vis_validation.h"

t_ant			*find_ant(t_iteration *iteration, int index)
{
	t_ant		*current;

	current = iteration->ant;
	while (current)
	{
		if (current->ant_index == index)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void			push_new_ant(t_ant **ant, t_ant *new_ant)
{
	t_ant		**head;
	t_ant		*pr;

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

t_room			*cur_room(t_input *data, t_ant *ant)
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
		printf("cur_room %d\n", i);

		if ((prev_ant = find_ant(iter, ant->ant_index)) != NULL)
			res_room = prev_ant->room;
		else if (res_room == NULL)
			res_room = find_room(data, data->st_room);
		i++;
	}
	printf("cur_room\n");
	return (res_room);
}

t_ant			*create_ant(t_input *data, char **steps)
{
	t_ant		*ant;

	ant = (t_ant *)malloc(sizeof(t_ant));
	ant->ant_index = ft_atoi(steps[0] + 1);
	ant->next = NULL;
	ant->room = find_room(data, steps[1]);
	ant->move = 1;
	printf("new ant to be created %d\n", ant->ant_index);
//	printf("antindex %s\n", (char*)data->iteration);
	if (data->iteration != NULL)
	{
		printf("o\n");
		ant->cur_room = cur_room(data, ant);
		printf("fg\n");

	}else
		ant->cur_room = find_room(data, data->st_room);
	if (ant->cur_room->name == data->st_room)
		ant->type = FIRST;
	else
		ant->type = MIDDLE;
	printf("new ant %d\n", ant->ant_index);
	return (ant);
}

t_iteration		*create_iteration(t_input *data, char *line)
{
	t_iteration *iter;
	char		**objs;
	char		**steps;
	int			i;

	i = 0;
	objs = ft_strsplit(line, ' ');
	iter = (t_iteration *)malloc(sizeof(t_iteration));
	iter->index = 0;
	iter->ant = NULL;
	iter->ants_num = 0;
	while (objs[i] != NULL)
	{
		steps = ft_strsplit(objs[i++], '-');
		printf("steps -- L %s : %s\n", steps[0], steps[1]);
		push_new_ant(&(iter->ant), create_ant(data, steps));
		printf("new ant pushed -- %d\n", iter->ant->ant_index);
		iter->ants_num += 1;
		ft_free_strsplit(steps);
	}
	iter->next = NULL;
	ft_free_strsplit(objs);
	return (iter);
}
