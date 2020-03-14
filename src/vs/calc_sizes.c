/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sizes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:19:59 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	keep_w_to_h_ratio(t_sizes *sizes)
{
	double ratio;

	ratio = (double)sizes->room_hight / sizes->room_width;
	while (ratio > 0.8)
	{
		sizes->room_hight -= 1;
		ratio = (double)sizes->room_hight / sizes->room_width;
	}
	while (ratio < 0.8)
	{
		sizes->room_width -= 1;
		ratio = (double)sizes->room_hight / sizes->room_width;
	}
}

void	convert_coords(t_sizes *sizes, t_room *room)
{
	int multiplier_x;
	int multiplier_y;

	multiplier_x = 0;
	multiplier_y = 0;
	while (sizes->min_x / sizes->divider_x + multiplier_x !=
										room->x / sizes->divider_x)
		multiplier_x += 1;
	while (sizes->min_y / sizes->divider_y + multiplier_y !=
										room->y / sizes->divider_y)
		multiplier_y += 1;
	room->x = sizes->space_w * multiplier_x + sizes->bounds +
							sizes->room_width * multiplier_x;
	room->y = sizes->space_h * multiplier_y + sizes->bounds +
							sizes->room_hight * multiplier_y;
}

void	calc_rooms_size(t_sizes *sizes)
{
	sizes->room_width = sizes->screen_w / (sizes->cels_num_w + 1);
	sizes->space_w = sizes->room_width / 5;
	sizes->bounds = sizes->room_width / 3;
	sizes->room_width = (sizes->screen_w - (sizes->bounds * 2) -
			(sizes->space_w * sizes->cels_num_w)) / (sizes->cels_num_w + 1);
	sizes->space_w = sizes->room_width / 4;
	sizes->bounds = sizes->room_width / 2;
	sizes->room_hight = sizes->screen_h / (sizes->cels_num_h + 1);
	sizes->space_h = sizes->room_hight / 5;
	sizes->room_hight = (sizes->screen_h - (sizes->bounds * 2) -
			(sizes->space_h * sizes->cels_num_h)) / (sizes->cels_num_h + 1);
	sizes->space_h = sizes->room_hight / 4;
	keep_w_to_h_ratio(sizes);
}
