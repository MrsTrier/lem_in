/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:08:48 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/11 16:32:34 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_tf;

	i = 0;
	j = 0;
	len_tf = (size_t)ft_strlen(to_find);
	if (*str && !*to_find)
		return ((char *)str);
	if (!*str && !*to_find)
		return ((char *)str);
	while (str[i] != '\0' && len_tf <= len)
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
				return ((char *)(str + i));
			j++;
		}
		i++;
		len--;
	}
	return ((char *)NULL);
}
