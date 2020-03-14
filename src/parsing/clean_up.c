/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:11:42 by vshelia           #+#    #+#             */
/*   Updated: 2020/03/04 13:36:42 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	free_links(t_lst *nodes_list)
{
	t_avl_tree	*node;

	while (nodes_list)
	{
		node = (t_avl_tree *)(nodes_list->content);
		free(node->content);
		free(node);
		lst_del(&nodes_list, 'f');
	}
}

void		free_farm(t_farm *farm)
{
	t_avl_tree	*node;
	t_room		*room;

	free(farm->map);
	while (farm->nodes_list)
	{
		node = (t_avl_tree *)farm->nodes_list->content;
		room = (t_room *)node->content;
		free(room->name);
		free_links(room->nodes_list);
		free(room);
		free(node);
		lst_del(&(farm->nodes_list), 'f');
	}
}

void		free_set_of_paths(t_lst **set_of_paths)
{
	t_path	*path;
	t_lst	**temp;

	while (*set_of_paths)
	{
		path = (t_path *)((*set_of_paths)->content);
		temp = &(path->path);
		while (*temp)
			lst_del(temp, 'f');
		free(path);
		lst_del(set_of_paths, 'f');
	}
}
