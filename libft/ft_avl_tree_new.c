/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:21:21 by vshelia           #+#    #+#             */
/*   Updated: 2020/01/21 21:35:42 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_avl_tree	*ft_avl_tree_new(void *content)
{
	t_avl_tree	*new_node;

	new_node = (t_avl_tree *)ft_memalloc(sizeof(*new_node));
	if (!new_node)
		ft_error("Error in memory allocation (ft_avl_tree_new)");
	new_node->content = content;
	new_node->height = 1;
	return (new_node);
}
