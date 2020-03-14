/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_search.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:33:26 by vshelia           #+#    #+#             */
/*   Updated: 2020/01/23 16:51:21 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_avl_tree	*ft_avl_tree_search(t_avl_tree *node, void *content,
		int (*compare)(void *, void *))
{
	int	compared;

	while (node && (compared = compare(content, node->content)))
	{
		if (compared > 0)
			node = node->right;
		else
			node = node->left;
	}
	return (node);
}
