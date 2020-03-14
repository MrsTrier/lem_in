/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_preorder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:55:16 by vshelia           #+#    #+#             */
/*   Updated: 2020/01/23 14:07:42 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_avl_tree_preorder(t_avl_tree *node, void (*f)(void *))
{
	if (node)
	{
		f(node);
		ft_avl_tree_preorder(node->left, f);
		ft_avl_tree_preorder(node->right, f);
	}
}
