/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:33:13 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/13 14:52:16 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t i;
	size_t i_d;

	i = 0;
	i_d = ft_strlen(dest);
	while (src[i] != '\0' && i < nb)
	{
		dest[i_d++] = src[i++];
	}
	dest[i_d] = '\0';
	return (dest);
}
