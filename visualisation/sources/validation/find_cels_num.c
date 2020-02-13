
# include "validation.h"
# include "errors.h"
# include <stdio.h>
# include "visualization.h"

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

void	find_cels_num(t_sizes *sizes, t_input data)
{
	sizes->max_y = find_max_coord(data, 'y');
	sizes->max_x = find_max_coord(data, 'x');
	sizes->min_y = find_min_coord(data, 'y');
	sizes->min_x = find_min_coord(data, 'x');
	sizes->cels_num_w = (sizes->max_x < 0) ? -(sizes->max_x - (-1 * sizes->min_x)) : sizes->max_x - sizes->min_x;
	sizes->cels_num_h = (sizes->max_y < 0) ? -(sizes->max_y - (-1 * sizes->min_y)) : sizes->max_y - sizes->min_y;
	printf("\nMIN X ---> %d\nMIN Y ---> %d\n", sizes->min_x, sizes->min_y);
	printf("\nMAX X ---> %d\nMAX Y ---> %d\n", sizes->max_x, sizes->max_y);
	printf("\nCels num in horizontal ---> %d\n", sizes->cels_num_w);
	printf("\nCels num in vertical ---> %d\n", sizes->cels_num_h);
}
