/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:03:31 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/07 17:41:02 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*sorc;
	unsigned char		ch;

	dest = (unsigned char *)dst;
	sorc = (const unsigned char *)src;
	ch = (unsigned char)c;
	if (dest && sorc)
	{
		while (n)
		{
			*dest = *sorc;
			if (*sorc == ch)
				return ((void *)(dest + 1));
			dest++;
			sorc++;
			n--;
		}
	}
	return (NULL);
}
