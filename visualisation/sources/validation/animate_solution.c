
# include "validation.h"
# include "errors.h"
# include <stdio.h>
# include "visualization.h"

void	rects_for_room(t_input data, t_sizes *sizes)
{
	while (data.room != NULL)
	{
		convert_coords(sizes, data.room);
		data.room = data.room->next;
	}
}

void	placerooms(t_input data, t_sizes *sizes)
{
	find_cels_num(sizes, data);
	calc_rooms_size(sizes);
	calc_additional_metrics(sizes);
	rects_for_room(data, sizes);
}

void	animate_solution(t_input data, t_vis_tools *vs)
{
	bool		quit;
	SDL_Event	e;
	t_sizes		sizes;
	int			i;

	i = 0;
	if (!init(vs, &sizes))
		error_found(ERR_INIT_SDL);
	else
	{
		if (!init_surface(vs))
			printf("Failed to load media!\n");
		else
		{
			quit = 0;
			placerooms(data, &sizes);
			while (!quit)
			{
				display_links(data, &sizes, vs);
				display_rooms(data, &sizes, vs);
				display_ants(&data, i, vs, &sizes);
				i++;
				SDL_RenderPresent(vs->renderer);
				SDL_Delay(1000 / 1);
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
						quit = 1;
				}
			}
		}
	}
}
