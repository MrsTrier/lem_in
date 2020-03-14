/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_journey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:48:21 by vshelia           #+#    #+#             */
/*   Updated: 2020/03/11 13:51:42 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>

static void	write_ant(char *ant_number, char *ant_room)
{
	if (!ant_number)
		ft_error("Error in memory allocation (write_ant)");
	write(1, "L", 1);
	write(1, ant_number, ft_strlen(ant_number));
	write(1, "-", 1);
	write(1, ant_room, ft_strlen(ant_room));
	write(1, " ", 1);
	free(ant_number);
}

static void	move_in_reverse_order(t_lst *path_previous, t_lst *path)
{
	unsigned	ant_number;

	if (path->next)
		move_in_reverse_order(path, path->next);
	ant_number = ((t_room *)(path_previous->content))->visited;
	if (ant_number)
	{
		if (((t_room *)(path->content))->position != 'e')
			((t_room *)(path->content))->visited = ant_number;
		else
			((t_room *)(path->content))->visited++;
		((t_room *)(path_previous->content))->visited = 0;
		write_ant(ft_ulltoa_base(ant_number, 10),
			((t_room *)(path->content))->name);
	}
}

static void	move_on_paths(t_farm *farm)
{
	t_lst	*paths;
	t_lst	*path;

	paths = farm->set_of_paths;
	while (paths)
	{
		if (((t_path *)(paths->content))->ants_on_path)
		{
			path = ((t_path *)(paths->content))->path->next;
			if (path->next)
				move_in_reverse_order(path, path->next);
		}
		else
			break ;
		paths = paths->next;
	}
}

static void	move_from_start(t_farm *farm)
{
	t_lst		*paths;
	t_path		*path;
	t_room		*room;
	unsigned	ant_number;

	paths = farm->set_of_paths;
	while (paths)
	{
		path = (t_path *)(paths->content);
		if (farm->start_room->visited > path->priority_value)
		{
			room = (t_room *)(path->path->next->content);
			ant_number = farm->number_of_ants - farm->start_room->visited + 1;
			room->visited = (room->position != 'e') ? ant_number
				: room->visited + 1;
			farm->start_room->visited--;
			write_ant(ft_ulltoa_base(ant_number, 10), room->name);
		}
		else
			break ;
		paths = paths->next;
	}
}

void		move_ants(t_farm *farm)
{
	farm->start_room->visited = farm->number_of_ants;
	while (farm->end_room->visited != farm->number_of_ants)
	{
		move_on_paths(farm);
		move_from_start(farm);
		write(1, "\n", 1);
		farm->steps_counted++;
	}
}
