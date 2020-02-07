/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:10:39 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/13 14:37:27 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		count;
	char	*arr;

	i = 0;
	count = 0;
	if (!s || !f)
		return (NULL);
	while (s[i])
		if (f(s[i++]))
			count++;
	if (!(arr = (char *)malloc(count + 1)))
		return (NULL);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (f(s[i]))
			arr[count++] = f(s[i]);
		i++;
	}
	arr[count] = '\0';
	return (arr);
}
