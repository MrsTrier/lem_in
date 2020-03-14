/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:24:38 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/10 15:06:22 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *str1;
	const unsigned char *str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	if (str1 && str2 && n)
	{
		while (n && *str1 == *str2)
		{
			n--;
			if (n)
			{
				str1++;
				str2++;
			}
		}
		return ((int)(*str1 - *str2));
	}
	return (0);
}
