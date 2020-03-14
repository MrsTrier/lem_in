/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_inorder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:58:42 by vshelia           #+#    #+#             */
/*   Updated: 2020/01/23 14:08:00 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_avl_tree_inorder(t_avl_tree *node, void (*f)(void *))
{
	if (node)
	{
		ft_avl_tree_inorder(node->left, f);
		f(node);
		ft_avl_tree_inorder(node->right, f);
	}
}
