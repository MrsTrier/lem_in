/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:14:20 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/09 18:52:10 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *elem;

	elem = (t_list *)ft_memalloc(sizeof(*elem));
	if (elem && content && content_size)
	{
		elem->content = ft_memalloc(content_size);
		(void)ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
	}
	return (elem);
}
