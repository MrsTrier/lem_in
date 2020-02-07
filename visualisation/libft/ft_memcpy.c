/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:42:56 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/19 19:43:00 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cur;

	if (dst == src)
		return (dst);
	cur = 0;
	while (cur < n)
	{
		((unsigned char *)dst)[cur] = ((unsigned char *)src)[cur];
		cur++;
	}
	return (dst);
}
