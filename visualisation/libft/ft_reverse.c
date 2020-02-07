/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:54:02 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/11 13:15:00 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse(char *s)
{
	int i;
	int tmp;
	int len;

	i = 0;
	len = ft_strlen(s);
	while (len > i)
	{
		len--;
		tmp = s[i];
		s[i] = s[len];
		s[len] = tmp;
		i++;
	}
	return (s);
}
