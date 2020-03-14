/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:29:44 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/10 18:54:53 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(int n)
{
	size_t len;

	len = 0;
	if (n < 0)
		len++;
	else if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*new_str;
	size_t	size;
	int		m;

	size = count_len(n);
	new_str = ft_strnew(size);
	if (new_str)
	{
		if (n < 0)
			new_str[0] = '-';
		size--;
		if (n == 0)
			new_str[0] = '0';
		while (n)
		{
			m = n % 10;
			if (m < 0)
				m = -m;
			new_str[size] = '0' + m;
			size--;
			n /= 10;
		}
	}
	return (new_str);
}
