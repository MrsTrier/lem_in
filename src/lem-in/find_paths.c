/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:42:00 by vshelia           #+#    #+#             */
/*   Updated: 2020/03/11 15:02:21 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*breadth_first_search(t_room *start_room)
{
	t_search_data	sd;
	t_room			*end_room;

	ft_bzero(&sd, sizeof(sd));
	start_room->visited = 1;
	lst_push(&(sd.queue), start_room, 'f');
	sd.queue_end = sd.queue;
	while (sd.queue)
	{
		sd.room = (t_room *)(sd.queue->content);
		if (sd.room->has_preferable_link && !sd.room->preferable_was_used)
			end_room = visit_preferable_link(&sd);
		else
			end_room = visit_links(&sd, 1);
		if (end_room)
			break ;
		lst_del(&(sd.queue), 'f');
		search_by_preferable_link(&sd);
	}
	while (sd.queue)
		lst_del(&(sd.queue), 'f');
	while (sd.search_by_preferable)
		lst_del(&(sd.search_by_preferable), 'f');
	return (end_room);
}

static t_path	*recover_path(t_room *end_room)
{
	t_path		*path;
	t_avl_tree	*predecessor_link_node;
	t_room		*predecessor_room;

	if (!(path = (t_path *)ft_memalloc(sizeof(*path))))
		ft_error("Error in memory allocation (recover_path)");
	while (end_room->predecessor)
	{
		lst_push(&(path->path), end_room, 'f');
		path->length++;
		predecessor_room = (t_room *)(end_room->predecessor->content);
		predecessor_link_node = ft_avl_tree_search(end_room->links,
			predecessor_room->name, cmp_str_t_link);
		if (((t_link *)(predecessor_link_node->content))->edge_weight)
		{
			((t_link *)(predecessor_link_node->content))->edge_weight = -1;
			end_room->has_preferable_link = 1;
		}
		lst_del(&(end_room->predecessor), 'f');
		end_room = predecessor_room;
	}
	lst_push(&(path->path), end_room, 'f');
	return (path);
}

t_path			*find_the_shortest_path(t_farm *farm,
				void (*modify_farm)(t_path *))
{
	t_path	*shortest_path;
	t_room	*end_room;

	shortest_path = NULL;
	end_room = breadth_first_search(farm->start_room);
	if (end_room)
	{
		shortest_path = recover_path(end_room);
		if (modify_farm)
			modify_farm(shortest_path);
	}
	set_rooms_unvisited(farm->nodes_list);
	return (shortest_path);
}

static unsigned	zero_edges_amount(t_lst *nodes_list)
{
	unsigned	removed_edges;
	t_room		*room;
	t_lst		*nodes_l_links;
	t_link		*link;

	removed_edges = 0;
	while (nodes_list)
	{
		room = (t_room *)(((t_avl_tree *)nodes_list->content)->content);
		nodes_l_links = room->nodes_list;
		while (nodes_l_links)
		{
			link = (t_link *)(((t_avl_tree *)nodes_l_links->content)->content);
			if (link->edge_weight == 0)
				removed_edges++;
			nodes_l_links = nodes_l_links->next;
		}
		nodes_list = nodes_list->next;
	}
	return (removed_edges);
}

void			find_paths(t_farm *farm)
{
	unsigned	removed_edges;
	unsigned	previous_value;

	if (farm->start_room->links)
	{
		removed_edges = 0;
		while (1)
		{
			previous_value = removed_edges;
			farm->set_of_paths = NULL;
			find_disjoint_paths(farm);
			if (farm->set_of_paths)
			{
				set_paths_data(farm->set_of_paths);
				lst_push(&(farm->sets_of_paths), farm->set_of_paths, 'b');
				remove_some_links(farm);
				removed_edges = zero_edges_amount(farm->nodes_list);
			}
			if (removed_edges == previous_value)
				break ;
		}
		if (farm->sets_of_paths)
			best_set_searching(farm);
	}
}
