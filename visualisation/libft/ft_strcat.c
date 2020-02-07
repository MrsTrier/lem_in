/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:35:20 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/13 15:48:48 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i_d;
	int i_s;

	i_d = 0;
	i_s = 0;
	while (dest[i_d] != '\0')
		i_d++;
	while (src[i_s] != '\0')
		dest[i_d++] = src[i_s++];
	dest[i_d] = '\0';
	return (dest);
}
