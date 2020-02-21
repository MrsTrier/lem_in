
# include "validation.h"
# include "errors.h"
# include "visualization.h"

# include <fcntl.h>
t_vis_tools		*create_vs(void)
{
	t_vis_tools	*vs;

	if (!(vs = (t_vis_tools *)ft_memalloc(sizeof(t_vis_tools))))
		error_found(ERR_VS_INIT);
	vs->window = NULL;
	vs->renderer = NULL;
	vs->font = NULL;
	vs->room_start_end = NULL;
	vs->room_middle = NULL;
	vs->ant = NULL;
	vs->next = NULL;
	vs->strt_displayed = 0;
	vs->textColor.r = 225;
	vs->textColor.g = 225;
	vs->textColor.b = 225;
	vs->textColor.a = 0;
	vs->speed = 500;
	return (vs);
}

void	free_surface(t_vis_tools *vs)
{
	SDL_FreeSurface(vs->background);
	vs->background = NULL;
	SDL_FreeSurface(vs->rooms);
	vs->rooms = NULL;
	SDL_FreeSurface(vs->ant);
	vs->ant = NULL;
}

void	free_vs(t_vis_tools **vs)
{
	if (vs && *vs)
	{
		free_surface(*vs);
		DESTROY_TXTR((*vs)->next);
		DESTROY_TXTR((*vs)->ant_texture);
		DESTROY_TXTR((*vs)->background_texture);
		DESTROY_TXTR((*vs)->room_texture);
		DESTROY_TXTR((*vs)->room_middle);
		DESTROY_TXTR((*vs)->room_start_end);
		TTF_CloseFont((*vs)->font);
		if ((*vs)->renderer)
			SDL_DestroyRenderer((*vs)->renderer);
		if ((*vs)->window)
			SDL_DestroyWindow((*vs)->window);
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
		free((*vs));
		(*vs) = NULL;
	}
}

int			main(int ac, char **av)
{
	char		*res;
	t_input		data;
	t_vis_tools	*vs;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (ac == 2)
	{
		vs = create_vs();
		read_validate(&res, &data, fd);
		animate_solution(data, vs);
		free_vs(&vs);
		free_room(&data);
		free_links(&data);
		free_iter(&data);
	}
	return (0);
}