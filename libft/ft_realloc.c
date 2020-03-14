/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:56:02 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/12 15:13:17 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size, size_t new_size)
{
	void *new_mem;

	new_mem = malloc(new_size);
	if (new_size < size)
		size = new_size;
	(void)ft_memcpy(new_mem, ptr, size);
	free(ptr);
	return (new_mem);
}
