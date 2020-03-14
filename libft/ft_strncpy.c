/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:48:45 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/06 21:34:39 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	void *after_null_symb;

	after_null_symb = ft_memccpy((void *)dst, (const void *)src, '\0', len);
	if (after_null_symb)
		ft_bzero(after_null_symb, len - ft_strlen(src) - 1);
	return (dst);
}
