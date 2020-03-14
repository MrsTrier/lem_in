/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_paths_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:45:21 by vshelia           #+#    #+#             */
/*   Updated: 2020/03/11 14:24:00 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static unsigned	count_set_capacity(unsigned number_of_ants, t_lst *set_of_paths)
{
	t_lst	*paths;
	t_path	*path;

	while (number_of_ants)
	{
		paths = set_of_paths;
		while (paths)
		{
			path = (t_path *)(paths->content);
			if (number_of_ants > path->priority_value)
			{
				path->ants_on_path++;
				number_of_ants--;
			}
			else
				break ;
			paths = paths->next;
		}
	}
	path = (t_path *)(set_of_paths->content);
	path->steps_to_move = path->length + (path->ants_on_path - 1);
	return (path->steps_to_move);
}

static void		create_capacities_array(t_set_search_data *sd, t_farm *farm)
{
	sd->sets_of_paths = farm->sets_of_paths;
	while (sd->sets_of_paths)
	{
		sd->amount_of_sets++;
		sd->sets_of_paths = sd->sets_of_paths->next;
	}
	sd->sets_capacities = (unsigned *)
		ft_memalloc(sizeof(*(sd->sets_capacities)) * sd->amount_of_sets);
	if (!(sd->sets_capacities))
		ft_error("Error in memory allocation (create_capacities_array)");
}

static void		find_list_by_index(t_set_search_data *sd, t_farm *farm)
{
	sd->sets_of_paths = farm->sets_of_paths;
	while (sd->least_value && sd->sets_of_paths)
	{
		sd->least_value--;
		sd->sets_of_paths = sd->sets_of_paths->next;
	}
	farm->set_of_paths = (t_lst *)(sd->sets_of_paths->content);
}

void			best_set_searching(t_farm *farm)
{
	t_set_search_data	sd;

	ft_bzero(&sd, sizeof(sd));
	create_capacities_array(&sd, farm);
	sd.sets_of_paths = farm->sets_of_paths;
	while (sd.sets_of_paths)
	{
		sd.current_set = (t_lst *)(sd.sets_of_paths->content);
		sd.sets_capacities[sd.i] = count_set_capacity(farm->number_of_ants,
			sd.current_set);
		sd.i++;
		sd.sets_of_paths = sd.sets_of_paths->next;
	}
	sd.least_value = 0;
	sd.i = 1;
	while (sd.i < sd.amount_of_sets)
	{
		if (sd.sets_capacities[sd.i] < sd.sets_capacities[sd.least_value])
			sd.least_value = sd.i;
		sd.i++;
	}
	free(sd.sets_capacities);
	find_list_by_index(&sd, farm);
}
