/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:42:21 by vshelia           #+#    #+#             */
/*   Updated: 2020/03/11 15:30:42 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>

static void	show_usage(void)
{
	write(1, USAGE, ft_strlen(USAGE));
}

static void	free_all(t_farm *farm)
{
	free_farm(farm);
	while (farm->sets_of_paths)
	{
		free_set_of_paths((t_lst **)&(farm->sets_of_paths->content));
		lst_del(&(farm->sets_of_paths), 'f');
	}
}

static void	show_paths(t_lst *set)
{
	t_path	*path;
	char	*length;
	t_lst	*rooms;

	while (set)
	{
		path = (t_path *)(set->content);
		rooms = path->path;
		if (!(length = ft_ulltoa_base(path->length, 10)))
			ft_error("Error in memory allocation (show_paths)");
		write(1, length, ft_strlen(length));
		write(1, ": ", 2);
		free(length);
		while (rooms)
		{
			write(1, ((t_room *)(rooms->content))->name,
					ft_strlen(((t_room *)(rooms->content))->name));
			write(1, " ", 1);
			rooms = rooms->next;
		}
		write(1, "\n", 1);
		set = set->next;
	}
}

static void	show_more(t_farm *farm)
{
	t_lst	*sets;
	char	*steps;

	write(1, "\n", 1);
	sets = farm->sets_of_paths;
	while (sets)
	{
		if (sets->content == farm->set_of_paths)
			write(1, BOLD, 4);
		show_paths((t_lst *)(sets->content));
		write(1, "\e[0m-----\n", 10);
		sets = sets->next;
	}
	write(1, "\nSteps counted: ", 16);
	if (!(steps = ft_ulltoa_base(farm->steps_counted, 10)))
		ft_error("Error in memory allocation (show_more)");
	write(1, steps, ft_strlen(steps));
	free(steps);
	write(1, "\n", 1);
}

int			main(int argc, char **argv)
{
	t_farm	farm;
	int		verbose;

	verbose = 0;
	if (argc == 1 || (argc == 2 &&
		((verbose = ft_strequ(argv[1], "-v")) ||
		(verbose = ft_strequ(argv[1], "--verbose")))))
	{
		build_farm(&farm);
		write(1, farm.map, ft_strlen(farm.map));
		write(1, "\n", 1);
		find_paths(&farm);
		if (farm.set_of_paths)
		{
			move_ants(&farm);
			if (verbose)
				show_more(&farm);
		}
		else
			write(1, "No paths found\n", 15);
		free_all(&farm);
	}
	else
		show_usage();
	return (0);
}
