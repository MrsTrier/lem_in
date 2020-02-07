/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:29:27 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/12 12:23:16 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	unsigned int	j;
	char			*arr;

	i = 0;
	j = 0;
	if (!s || !f)
		return (NULL);
	while (s[i] != '\0')
	{
		if (f(i, s[i]))
			j++;
		i++;
	}
	if (!(arr = (char *)malloc(j + 1)))
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i] != '\0')
	{
		if (f(i, s[i]))
			arr[j++] = (char)f(i, s[i]);
	}
	arr[j] = '\0';
	return ((char	*)arr);
}
