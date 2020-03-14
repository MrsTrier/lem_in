/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:24:23 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/07 16:29:48 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t len1;
	size_t len2;
	size_t min_len;

	len1 = ft_strlen(s1) + 1;
	len2 = ft_strlen(s2) + 1;
	min_len = (len1 < len2) ? len1 : len2;
	if (min_len > n)
		min_len = n;
	return (ft_memcmp((const void *)s1, (const void *)s2, min_len));
}
