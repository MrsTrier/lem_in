/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visit_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:10:21 by vshelia           #+#    #+#             */
/*   Updated: 2020/03/11 14:21:55 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		in_queue(t_lst *queue, t_room *room)
{
	while (queue)
	{
		if (queue->content == room)
			return (1);
		queue = queue->next;
	}
	return (0);
}

static t_room	*visit_link(t_search_data *sd, t_link *link, int weight)
{
	t_room	*linked_room;
	int		visit_twice;

	visit_twice = 0;
	if (link->edge_weight == weight)
	{
		linked_room = link->room;
		if (!linked_room->visited ||
			(weight == -1 && sd->queue_end == sd->queue) ||
			(visit_twice = (weight == -1 && in_queue(sd->queue, linked_room))))
		{
			if (visit_twice)
				lst_del(&(linked_room->predecessor), 'f');
			lst_push(&(linked_room->predecessor), sd->room, 'f');
			if (linked_room->position == 'e')
				return (linked_room);
			linked_room->visited = 1;
			lst_push(&(sd->queue_end), linked_room, 'b');
			sd->queue_end = sd->queue_end->next;
		}
	}
	return (NULL);
}

t_room			*visit_links(t_search_data *sd, int weight)
{
	t_lst		*nodes_list;
	t_avl_tree	*node;
	t_room		*end_room;

	nodes_list = sd->room->nodes_list;
	while (nodes_list)
	{
		node = (t_avl_tree *)(nodes_list->content);
		if ((end_room = visit_link(sd, (t_link *)(node->content), weight)))
			break ;
		nodes_list = nodes_list->next;
	}
	return (end_room);
}

t_room			*visit_preferable_link(t_search_data *sd)
{
	t_room	*end_room;
	t_lst	*queue_end;

	queue_end = sd->queue_end;
	end_room = visit_links(sd, -1);
	if (sd->queue_end == queue_end)
		return (end_room);
	if (((t_room *)(sd->queue_end->content))->amount_of_links > 2)
	{
		((t_room *)(sd->queue_end->content))->preferable_was_used = 1;
		if (!((t_room *)(sd->queue_end->content))->was_in_another_queue)
		{
			lst_push(&(sd->search_by_preferable), sd->queue_end->content, 'b');
			((t_room *)(sd->queue_end->content))->was_in_another_queue = 1;
		}
	}
	return (end_room);
}

void			search_by_preferable_link(t_search_data *sd)
{
	if (!sd->queue && sd->search_by_preferable)
	{
		lst_push(&(sd->queue), sd->search_by_preferable->content, 'f');
		sd->queue_end = sd->queue;
		((t_room *)sd->search_by_preferable->content)->preferable_was_used = 0;
		lst_del(&(sd->search_by_preferable), 'f');
	}
}
