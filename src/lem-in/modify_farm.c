/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_farm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:30:42 by vshelia           #+#    #+#             */
/*   Updated: 2020/03/09 19:30:55 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_rooms_unvisited(t_lst *nodes_list)
{
	t_avl_tree	*node;
	t_room		*room;

	while (nodes_list)
	{
		node = (t_avl_tree *)(nodes_list->content);
		room = (t_room *)(node->content);
		room->visited = 0;
		room->preferable_was_used = 0;
		while (room->predecessor)
			lst_del(&(room->predecessor), 'f');
		nodes_list = nodes_list->next;
	}
}

void		set_no_path(t_path *path)
{
	t_lst		*rooms_list;
	t_room		*room;
	t_room		*next_room;
	t_avl_tree	*link_node;

	rooms_list = path->path;
	while (rooms_list->next)
	{
		room = (t_room *)(rooms_list->content);
		next_room = (t_room *)(rooms_list->next->content);
		link_node = ft_avl_tree_search(room->links, next_room->name,
				cmp_str_t_link);
		((t_link *)(link_node->content))->edge_weight = 0;
		rooms_list = rooms_list->next;
	}
}

void		set_visited_path(t_path *path)
{
	t_lst		*rooms_list;
	t_room		*room;

	rooms_list = path->path->next;
	while (rooms_list->next)
	{
		room = (t_room *)(rooms_list->content);
		room->visited = 1;
		rooms_list = rooms_list->next;
	}
}

static void	iterate_links_to_recover(t_room *room)
{
	t_lst		*nodes_list;
	t_avl_tree	*node;
	t_link		*link;

	nodes_list = room->nodes_list;
	while (nodes_list)
	{
		node = (t_avl_tree *)(nodes_list->content);
		link = (t_link *)(node->content);
		if (link->edge_weight)
		{
			link->edge_weight = 1;
			((t_link *)
				((ft_avl_tree_search(link->room->links, room->name,
					cmp_str_t_link))->content))->edge_weight = 1;
		}
		nodes_list = nodes_list->next;
	}
}

void		recover_links(t_lst *nodes_list)
{
	t_avl_tree	*node;

	while (nodes_list)
	{
		node = (t_avl_tree *)(nodes_list->content);
		iterate_links_to_recover((t_room *)(node->content));
		((t_room *)(node->content))->has_preferable_link = 0;
		nodes_list = nodes_list->next;
	}
}
