/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:16:08 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/07 17:43:12 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*r_ptr;
	char		ch;

	r_ptr = NULL;
	ch = (char)c;
	if (s)
	{
		while (*s)
		{
			if (*s == ch)
				r_ptr = s;
			s++;
		}
		if (*s == ch)
			r_ptr = s;
		return ((char *)r_ptr);
	}
	return (NULL);
}
