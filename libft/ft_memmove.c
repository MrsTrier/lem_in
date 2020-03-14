/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:38:06 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/11 17:35:06 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *buf;

	buf = ft_memalloc(len);
	if (dst && src && buf && len)
	{
		(void)ft_memcpy(buf, src, len);
		(void)ft_memcpy(dst, buf, len);
		ft_memdel(&buf);
	}
	return (dst);
}
