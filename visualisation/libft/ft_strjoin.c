/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:10:26 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/16 19:36:26 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*frsh;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(frsh = (char *)malloc(i + 1)))
	{
		free(frsh);
		return (NULL);
	}
	i = 0;
	while (s1[j] != '\0')
		frsh[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		frsh[i++] = s2[j++];
	frsh[i] = '\0';
	return (frsh);
}
