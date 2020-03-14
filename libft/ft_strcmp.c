/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:13:15 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/07 16:29:33 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t len1;
	size_t len2;
	size_t min_len;

	len1 = ft_strlen(s1) + 1;
	len2 = ft_strlen(s2) + 1;
	min_len = (len1 < len2) ? len1 : len2;
	return (ft_memcmp((const void *)s1, (const void *)s2, min_len));
}
