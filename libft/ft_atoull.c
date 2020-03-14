/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:50:14 by vshelia           #+#    #+#             */
/*   Updated: 2019/12/23 15:48:50 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*space_passer(const char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

unsigned long long	ft_atoull(const char *str)
{
	const char			*pstr;
	unsigned long long	result;
	unsigned long long	r;

	result = 0;
	if (str)
	{
		str = space_passer(str);
		if (*str == '+' || *str == '-')
			str++;
		while (*str >= '0' && *str <= '9')
		{
			pstr = str + 1;
			r = 1;
			while (*pstr >= '0' && *pstr <= '9')
			{
				r *= 10;
				pstr++;
			}
			result += (*str - '0') * r;
			str++;
		}
	}
	return (result);
}
