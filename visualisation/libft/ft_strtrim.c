/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:33:41 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/16 19:37:35 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_blank(char const *s)
{
	int		i;
	char	*arr;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			return (NULL);
		i++;
	}
	if (!(arr = (char *)malloc(1)))
		return (NULL);
	return (arr);
}

char		*ft_strtrim(char *s)
{
	int		len;
	int		skip;
	int		i;
	char	*arr;

	if (!s || !ft_strlen(s))
		return ((char *)s);
	i = 0;
	if (ft_blank(s))
		return (ft_blank(s));
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	skip = i;
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	len = len - skip;
	i = 0;
	if (!(arr = (char *)malloc(len + 1)))
		return (NULL);
	while (i < len)
		arr[i++] = s[skip++];
	arr[i] = '\0';
	return (arr);
}
