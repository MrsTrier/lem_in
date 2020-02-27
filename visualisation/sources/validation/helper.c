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

#include "vis_validation.h"
#include <errno.h>

int		count_objs(char **objs)
{
	int obj_index;

	obj_index = 0;
	while (*objs != NULL)
	{
		obj_index++;
		objs++;
	}
	return (obj_index);
}

void	putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}

void	error_found(char *s)
{
	if (s)
	{
		write(2, s, ft_strlen(s));
		write(2, "\n", 1);
	}
	exit(1);
}
