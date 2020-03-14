/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:53:55 by vshelia           #+#    #+#             */
/*   Updated: 2019/12/23 15:53:21 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(long long n)
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

char			*ft_lltoa(long long n)
{
	char	*new_str;
	size_t	size;
	int		m;

	size = count_len(n);
	new_str = (char *)malloc(sizeof(*new_str) * (size + 1));
	if (new_str)
	{
		if (n < 0)
			new_str[0] = '-';
		new_str[size--] = '\0';
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
