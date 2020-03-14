/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 09:11:11 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/11 11:41:10 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	long	j;
	long	size_remaining;
	size_t	initial_length;

	if (dst && src)
	{
		i = 0;
		while (i < size && dst[i])
			i++;
		if (dst[i])
			return (size + ft_strlen(src));
		size_remaining = (long)(size - i - 1);
		initial_length = i;
		j = 0;
		while (j < size_remaining && src[j])
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (initial_length + ft_strlen(src));
	}
	return (0);
}
