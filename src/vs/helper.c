/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:36:52 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/04 12:36:55 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"
#include <unistd.h>

int			count_objs(char **objs)
{
	int		obj_index;

	obj_index = 0;
	while (*objs != NULL)
	{
		obj_index++;
		objs++;
	}
	return (obj_index);
}

void		error_found(char *s, const char *error)
{
	if (s)
	{
		if (error)
			s = ft_strjoin(s, error);
		write(2, s, ft_strlen(s));
		write(2, "\n", 1);
	}
	exit(1);
}

bool		is_int(const char *str)
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
	printf("is_int?\n");
	return (!str[i] && digits);
}
