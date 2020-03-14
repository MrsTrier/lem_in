/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:36:23 by vshelia           #+#    #+#             */
/*   Updated: 2019/12/24 20:52:42 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*space_passer(const char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

static int			sign_definer(const char **str)
{
	if (**str == '-')
	{
		(*str)++;
		return (-1);
	}
	if (**str == '+')
		(*str)++;
	return (1);
}

long long			ft_atoll(const char *str)
{
	const char			*pstr;
	unsigned long long	result;
	int					sign;
	unsigned long long	r;

	result = 0;
	sign = 1;
	if (str)
	{
		str = space_passer(str);
		sign = sign_definer(&str);
		while (ft_isdigit(*str))
		{
			pstr = str + 1;
			r = 1;
			while (ft_isdigit(*pstr))
			{
				r *= 10;
				pstr++;
			}
			result += (*str - '0') * r;
			str++;
		}
	}
	return ((long long)result * sign);
}
