/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 08:37:37 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/11 10:32:24 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	if (!needle || *needle == '\0')
		return ((char *)haystack);
	if (haystack)
	{
		i = 0;
		while (i < len && haystack[i])
		{
			j = i;
			k = 0;
			while (j < len && haystack[j] && needle[k]
					&& haystack[j] == needle[k])
			{
				j++;
				k++;
			}
			if (!needle[k])
				return ((char *)(haystack + i));
			i++;
		}
	}
	return (NULL);
}
