/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:17:16 by vshelia           #+#    #+#             */
/*   Updated: 2020/03/04 13:22:55 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	lst_push(t_lst **list, void *content, char position)
{
	t_lst	*new_node;
	t_lst	*temp;

	if (list)
	{
		new_node = (t_lst *)ft_memalloc(sizeof(*new_node));
		if (new_node)
		{
			new_node->content = content;
			if (*list && position == 'b')
			{
				temp = *list;
				while (temp->next)
					temp = temp->next;
				temp->next = new_node;
			}
			else
			{
				new_node->next = *list;
				*list = new_node;
			}
		}
		else
			ft_error("Error in memory allocation (lst_push)");
	}
}

void	lst_del(t_lst **list, char position)
{
	t_lst	*temp;

	if (list && *list)
	{
		temp = *list;
		if (temp->next && position == 'b')
		{
			while (temp->next->next)
				temp = temp->next;
			ft_memdel((void **)(&(temp->next)));
		}
		else
		{
			*list = (*list)->next;
			ft_memdel((void **)(&temp));
		}
	}
}

t_lst	*postorder_list_of_nodes(t_avl_tree *node)
{
	t_lst	*stack;
	t_lst	*stack_for_postorder;

	stack = NULL;
	stack_for_postorder = NULL;
	if (node)
	{
		lst_push(&stack, node, 'f');
		while (stack)
		{
			node = (t_avl_tree *)(stack->content);
			lst_del(&stack, 'f');
			lst_push(&stack_for_postorder, node, 'f');
			if (node->left)
				lst_push(&stack, node->left, 'f');
			if (node->right)
				lst_push(&stack, node->right, 'f');
		}
	}
	return (stack_for_postorder);
}

void	create_links_nodes_lists(t_lst *nodes_list)
{
	t_avl_tree	*node;

	while (nodes_list)
	{
		node = (t_avl_tree *)(nodes_list->content);
		((t_room *)(node->content))->nodes_list =
			postorder_list_of_nodes(((t_room *)(node->content))->links);
		nodes_list = nodes_list->next;
	}
}
