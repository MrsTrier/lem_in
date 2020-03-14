/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:38:07 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/10 16:14:27 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	char		*new_str;
	const char	*end;

	new_str = NULL;
	if (s)
	{
		while (is_whitespace(*s))
			s++;
		end = s;
		while (*end)
			end++;
		if (end != s)
			end--;
		while (is_whitespace(*end))
			end--;
		new_str = ft_strnew(end - s + 1);
		(void)ft_strncpy(new_str, s, end - s + 1);
	}
	return (new_str);
}
