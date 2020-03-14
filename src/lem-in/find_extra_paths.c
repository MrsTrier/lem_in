/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_extra_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:21:00 by vshelia           #+#    #+#             */
/*   Updated: 2020/03/11 14:40:21 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	set_visited_paths(t_lst *paths)
{
	while (paths)
	{
		set_visited_path((t_path *)(paths->content));
		paths = paths->next;
	}
}

void		find_disjoint_paths(t_farm *farm)
{
	t_path	*path;
	t_lst	*set_of_paths_last;

	while ((path = find_the_shortest_path(farm, NULL)))
	{
		if (farm->set_of_paths)
		{
			lst_push(&(set_of_paths_last), path, 'b');
			set_of_paths_last = set_of_paths_last->next;
		}
		else
		{
			lst_push(&(farm->set_of_paths), path, 'b');
			set_of_paths_last = farm->set_of_paths;
		}
		set_visited_paths(farm->set_of_paths);
		if (path->length == 1)
			((t_link *)
				(ft_avl_tree_search(((t_room *)(path->path->content))->links,
				((t_room *)(path->path->next->content))->name,
				cmp_str_t_link)->content))->edge_weight = 0;
	}
}

void		set_paths_data(t_lst *set_of_paths)
{
	t_path	*path;
	t_path	*next_path;

	while (set_of_paths->next)
	{
		path = (t_path *)(set_of_paths->content);
		next_path = (t_path *)(set_of_paths->next->content);
		next_path->shorter_paths_amount = path->shorter_paths_amount + 1;
		next_path->sum_of_shorter_paths_length =
			path->sum_of_shorter_paths_length + path->length;
		path->priority_value = path->length * path->shorter_paths_amount
			- path->sum_of_shorter_paths_length;
		set_of_paths = set_of_paths->next;
	}
	path = (t_path *)(set_of_paths->content);
	path->priority_value = path->length * path->shorter_paths_amount
		- path->sum_of_shorter_paths_length;
}

void		remove_some_links(t_farm *farm)
{
	t_lst	*set_of_paths;
	t_path	*path;

	set_of_paths = farm->set_of_paths;
	while (set_of_paths)
	{
		set_no_path((t_path *)set_of_paths->content);
		set_of_paths = set_of_paths->next;
	}
	if ((path = find_the_shortest_path(farm, set_no_path)))
	{
		while (path->path)
			lst_del(&(path->path), 'f');
		free(path);
	}
	recover_links(farm->nodes_list);
}
