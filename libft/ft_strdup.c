/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:39:07 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/06 20:12:47 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	size_t	size;
	char	*new_str;

	new_str = NULL;
	if (s1)
	{
		size = ft_strlen(s1) + 1;
		new_str = (char *)malloc(sizeof(*new_str) * size);
		if (new_str)
		{
			i = 0;
			while (s1[i])
			{
				new_str[i] = s1[i];
				i++;
			}
			new_str[i] = '\0';
		}
	}
	return (new_str);
}
