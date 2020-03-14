/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:56:14 by vshelia           #+#    #+#             */
/*   Updated: 2019/12/23 16:11:26 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(unsigned long long n, int base)
{
	size_t len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

char			*ft_ulltoa_base(unsigned long long n, int base)
{
	char	*possible_chrs;
	char	*new_str;
	size_t	size;

	possible_chrs = "0123456789abcdef";
	size = count_len(n, base);
	new_str = (char *)malloc(sizeof(*new_str) * (size + 1));
	if (new_str)
	{
		new_str[size--] = '\0';
		if (n == 0)
			new_str[0] = '0';
		while (n)
		{
			new_str[size] = possible_chrs[n % base];
			size--;
			n /= base;
		}
	}
	return (new_str);
}
