/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:22:04 by mcanhand          #+#    #+#             */
/*   Updated: 2020/01/17 14:22:04 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		is_int(const char *str)
{
	long	result;
	long	border;
	int		i;
	int		sign;
	int		digits;

	result = 0;
	digits = 0;
	border = (INT_MAX / 10);
	i = 0;
	while (str[i] == ' ')
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && ++digits)
	{
		if (((result > border || (result == border && (str[i] - '0') > 7))
			&& sign == 1)
			|| ((result > border || (result == border && (str[i] - '0') > 8))
				&& sign == -1))
			return (false);
		result = result * 10 + (str[i++] - '0');
	}
	return (!str[i] && digits);
}
