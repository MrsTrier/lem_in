/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cels_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:20:38 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"
#include "vis.h"

int		find_max_coord(t_input data, char c)
{
	int	max;
	int	next;

	max = (c == 'x') ? data.room->x : data.room->y;
	while (data.room->next != NULL)
	{
		next = (c == 'x') ? data.room->next->x : data.room->next->y;
		if (max < next)
			max = next;
		data.room = data.room->next;
	}
	return (max);
}

int		find_min_coord(t_input data, char c)
{
	int	min;
	int	next;

	min = (c == 'x') ? data.room->x : data.room->y;
	while (data.room->next != NULL)
	{
		next = (c == 'x') ? data.room->next->x : data.room->next->y;
		if (next < min)
			min = next;
		data.room = data.room->next;
	}
	return (min);
}

int		find_min_pos_coord(t_input data, char c, int max, int min)
{
	int	next;
	int	diff;

	diff = max;
	if (min <= 0)
	{
		while (data.room->next != NULL)
		{
			next = (c == 'x') ? data.room->x : data.room->y;
			if (next == 0)
				;
			if (next > 0)
				min = next - 0;
			else
				min = -next - 0;
			if (diff > min && min)
				diff = min;
			data.room = data.room->next;
		}
		return (diff);
	}
	else
		return (min);
}

void	find_cels_num(t_sizes *sizes, t_input data)
{
	sizes->max_y = find_max_coord(data, 'y');
	sizes->max_x = find_max_coord(data, 'x');
	sizes->min_y = find_min_coord(data, 'y');
	sizes->min_x = find_min_coord(data, 'x');
	sizes->divider_x = 1;
	sizes->divider_y = 1;
	sizes->cels_num_w = (sizes->max_x < 0) ?
			-(sizes->max_x - (-1 * sizes->min_x)) : sizes->max_x - sizes->min_x;
	sizes->cels_num_h = (sizes->max_y < 0) ?
			-(sizes->max_y - (-1 * sizes->min_y)) : sizes->max_y - sizes->min_y;
	if (sizes->cels_num_w > 20 || sizes->cels_num_h > 20)
	{
//		printf("MIN_x %d\n", sizes->min_x);
		sizes->divider_x = find_min_pos_coord(data, 'x', sizes->max_x, sizes->min_x);
		sizes->divider_y = find_min_pos_coord(data, 'y', sizes->max_y, sizes->min_y);
//		printf("divider_x %d\n", sizes->divider_x);
//		printf("divider_y %d\n", sizes->divider_y);
		sizes->cels_num_w = (sizes->max_x / sizes->divider_x < 0) ?
		-(sizes->max_x / sizes->divider_x -
		(-1 * sizes->min_x / sizes->divider_x)) :
		sizes->max_x / sizes->divider_x - sizes->min_x / sizes->divider_x;
		sizes->cels_num_h = (sizes->max_y / sizes->divider_y < 0) ?
		-(sizes->max_y / sizes->divider_y -
		(-1 * sizes->min_y / sizes->divider_y)) :
		sizes->max_y / sizes->divider_y - sizes->min_y / sizes->divider_y;
	}
}
