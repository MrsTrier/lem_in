/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_insert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:48:00 by vshelia           #+#    #+#             */
/*   Updated: 2020/01/23 14:52:42 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned		max_value(unsigned int h1, unsigned int h2)
{
	if (h1 > h2)
		return (h1);
	else
		return (h2);
}

static unsigned		get_height(t_avl_tree *node)
{
	if (node)
		return (node->height);
	return (0);
}

static int			get_balance(t_avl_tree *node)
{
	if (node)
		return (get_height(node->left) - get_height(node->right));
	return (0);
}

static t_avl_tree	*double_rotate(t_avl_tree *node, char direction)
{
	if (direction == 'l')
	{
		node->left = ft_avl_left_rotate(node->left);
		return (ft_avl_right_rotate(node));
	}
	else
	{
		node->right = ft_avl_right_rotate(node->right);
		return (ft_avl_left_rotate(node));
	}
}

t_avl_tree			*ft_avl_tree_insert(t_avl_tree *node, void *content,
		int (*compare)(void *, void *))
{
	int	compared;
	int	balance;

	if (node == NULL)
		return (ft_avl_tree_new(content));
	compared = compare(content, node->content);
	if (compared > 0)
		node->right = (ft_avl_tree_insert(node->right, content, compare));
	else if (compared < 0)
		node->left = (ft_avl_tree_insert(node->left, content, compare));
	else
		return (node);
	node->height = max_value(get_height(node->left), get_height(node->right))
		+ 1;
	balance = get_balance(node);
	if (balance >= 2 && compare(content, node->left->content) < 0)
		return (ft_avl_right_rotate(node));
	else if (balance >= 2 && compare(content, node->left->content) > 0)
		return (double_rotate(node, 'l'));
	else if (balance <= -2 && compare(content, node->right->content) > 0)
		return (ft_avl_left_rotate(node));
	else if (balance <= -2 && compare(content, node->right->content) < 0)
		return (double_rotate(node, 'r'));
	return (node);
}
