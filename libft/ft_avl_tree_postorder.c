/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_postorder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:01:10 by vshelia           #+#    #+#             */
/*   Updated: 2020/01/23 14:08:21 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_avl_tree_postorder(t_avl_tree *node, void (*f)(void *))
{
	if (node)
	{
		ft_avl_tree_postorder(node->left, f);
		ft_avl_tree_postorder(node->right, f);
		f(node);
	}
}
