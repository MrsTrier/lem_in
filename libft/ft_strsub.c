/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:52:56 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/10 16:11:31 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub_str;

	sub_str = NULL;
	if (s)
	{
		s_len = ft_strlen(s);
		if (start >= s_len)
			return (NULL);
		sub_str = ft_strnew(len);
		(void)ft_strncpy(sub_str, s + start, len);
	}
	return (sub_str);
}
