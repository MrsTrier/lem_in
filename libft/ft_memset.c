/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:46:43 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/08 20:36:50 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *dest;
	unsigned char ch;

	dest = (unsigned char *)b;
	ch = (unsigned char)c;
	if (dest)
	{
		while (len)
		{
			*dest = ch;
			dest++;
			len--;
		}
	}
	return (b);
}
