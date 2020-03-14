/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 10:45:54 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/11 16:52:50 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

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

static int			overflow_checker(unsigned long nb, int sign)
{
	if (nb <= LONG_MAX)
		return ((int)nb * sign);
	else
		return ((sign == -1) ? 0 : -1);
}

int					ft_atoi(const char *str)
{
	const char			*pstr;
	unsigned long		result;
	int					sign;
	unsigned long		r;

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
	return (overflow_checker(result, sign));
}
