/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:07:34 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/10 16:12:02 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*new_str;

	new_str = NULL;
	if (s1 && s2)
	{
		new_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (new_str)
		{
			i = 0;
			while (*s1)
			{
				new_str[i] = *s1;
				i++;
				s1++;
			}
			while (*s2)
			{
				new_str[i] = *s2;
				i++;
				s2++;
			}
		}
	}
	return (new_str);
}
