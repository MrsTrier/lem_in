
# include "visualization.h"
# include <stdio.h>



void	keep_w_to_h_ratio(t_sizes *sizes)
{
	bool status;
	double ratio;

	status = false;
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
	printf("width: %d\nhight: %d\n", sizes->room_width, sizes->room_hight);

}

void	convert_coords(t_sizes *sizes, t_room *room)
{
	int multiplier_x;
	int multiplier_y;

	multiplier_x = 0;
	multiplier_y = 0;
	printf("x: %d\ny: %d\n", room->x, room->y);
	while (sizes->min_x + multiplier_x != room->x)
		multiplier_x += 1;
	while (sizes->min_y + multiplier_y != room->y)
		multiplier_y += 1;
	room->x = sizes->space_w * multiplier_x + sizes->bounds + sizes->room_width * multiplier_x;
	room->y = sizes->space_h * multiplier_y + sizes->bounds + sizes->room_hight * multiplier_y;
	printf("space: %d\nx: %d\ny: %d\n", sizes->space_w, room->x, room->y);
}

void	calc_rooms_size(t_sizes *sizes)
{
	int free_space_w;
	int free_space_h;

	free_space_w = 0;
	free_space_w = 0;
	sizes->bounds = 10;
	free_space_w = sizes->screen_w - sizes->bounds * 2;
	sizes->room_width = free_space_w / (sizes->cels_num_w + 1);
	sizes->space_w = sizes->room_width / 3;
	sizes->room_width = (free_space_w - (sizes->space_w * sizes->cels_num_w)) / (sizes->cels_num_w + 1);

	free_space_h = sizes->screen_h - sizes->bounds * 2;
	sizes->room_hight = free_space_h / (sizes->cels_num_h + 1);
	sizes->space_h = sizes->room_hight / 3;
	sizes->room_hight = (free_space_h - (sizes->space_h * sizes->cels_num_h)) / (sizes->cels_num_h + 1);
	keep_w_to_h_ratio(sizes);
}
