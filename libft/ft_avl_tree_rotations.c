/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_rotations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:42:00 by vshelia           #+#    #+#             */
/*   Updated: 2020/01/23 14:25:42 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned	max_value(unsigned int h1, unsigned int h2)
{
	if (h1 > h2)
		return (h1);
	else
		return (h2);
}

static unsigned	get_height(t_avl_tree *node)
{
	if (node)
		return (node->height);
	return (0);
}

t_avl_tree		*ft_avl_left_rotate(t_avl_tree *node)
{
	t_avl_tree	*new_root;

	new_root = node->right;
	node->right = node->right->left;
	new_root->left = node;
	node->height = max_value(get_height(node->left),
			get_height(node->right)) + 1;
	new_root->height = max_value(get_height(new_root->left),
			get_height(new_root->right)) + 1;
	return (new_root);
}

t_avl_tree		*ft_avl_right_rotate(t_avl_tree *node)
{
	t_avl_tree	*new_root;

	new_root = node->left;
	node->left = node->left->right;
	new_root->right = node;
	node->height = max_value(get_height(node->left),
			get_height(node->right)) + 1;
	new_root->height = max_value(get_height(new_root->left),
			get_height(new_root->right)) + 1;
	return (new_root);
}
