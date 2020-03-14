/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:36:59 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/08 13:00:05 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;

	if (!needle || *needle == '\0')
		return ((char *)haystack);
	if (haystack)
	{
		i = 0;
		while (haystack[i])
		{
			j = i;
			k = 0;
			while (haystack[j] && needle[k] && haystack[j] == needle[k])
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
