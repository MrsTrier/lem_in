/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:13:27 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/10 16:21:45 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	new_str = NULL;
	if (s)
	{
		new_str = ft_strnew(ft_strlen(s));
		if (new_str)
		{
			i = 0;
			while (s[i])
			{
				new_str[i] = f(i, s[i]);
				i++;
			}
			new_str[i] = '\0';
		}
	}
	return (new_str);
}
