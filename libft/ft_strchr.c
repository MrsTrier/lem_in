/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:01:06 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/07 16:15:55 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char ch;

	ch = (char)c;
	if (s)
	{
		while (*s)
		{
			if (*s == ch)
				return ((char *)s);
			s++;
		}
		if (*s == ch)
			return ((char *)s);
	}
	return (NULL);
}
