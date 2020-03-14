/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:34:21 by vshelia           #+#    #+#             */
/*   Updated: 2020/03/11 15:26:42 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "parsing.h"

# define USAGE0 "Usage:\n\t./lem-in [-v | --verbose]\n"
# define USAGE1 "\t./lem-in < MAP_FILE\n"
# define USAGE2 "\tcat MAP_FILE | ./lem-in\n\n"
# define USAGE3 "\tThe map should be described in the next format:\n"
# define USAGE4 "\t\t" NOA "\n\t\t" TR "\n\t\t" TL "\n\n"
# define USAGE5 "\tExample:\n"
# define USAGE6 "\t\t4\n\t\t3 2 2\n\t\t##start\n\t\tstart 4 0\n\t\t##end\n"
# define USAGE7 "\t\tend 4 6\n\t\t4 0 4\n\t\t1 4 2\n\t\t2 4 4\n\t\t5 8 2\n"
# define USAGE8 "\t\t6 8 4\n\t\tstart-1\n\t\t3-4\n\t\t2-4\n\t\t1-5\n\t\t6-5\n"
# define USAGE9 "\t\tend-6\n\t\t1-2\n\t\t2-end\n\t\t3-start\n\n"
# define USAGE10 "\tThere are restrictions:\n"
# define USAGE11 "\t\t" NOA " is the the value"
# define USAGE12 " from 1 to 2147483647\n"
# define USAGE13 "\t\t" TR " names must be unique and "
# define USAGE14 "can't start with L or contain non-printable characters\n"
# define USAGE15 "\t\t" TR " coordinates must be unique and"
# define USAGE16 " the values from 1 to 2147483647 each\n"
# define USAGE17 "\t\t" TL " is created in both-sides, so "
# define USAGE18 "the same link in same or another order is an error\n"
# define USAGE19 "\n\t[-v | --verbose] - print found sets of paths and number "
# define USAGE20 "of ants steps\n"
# define USAGE21 USAGE0 USAGE1 USAGE2 USAGE3 USAGE4 USAGE5 USAGE6 USAGE7
# define USAGE22 USAGE21 USAGE8 USAGE9 USAGE10 USAGE11 USAGE12 USAGE13 USAGE14
# define USAGE23 USAGE22 USAGE15 USAGE16 USAGE17 USAGE18 USAGE19 USAGE20

# define USAGE USAGE23

typedef struct	s_search_data
{
	t_lst	*queue;
	t_lst	*queue_end;
	t_room	*room;
	t_lst	*search_by_preferable;
}				t_search_data;

typedef struct	s_set_search_data
{
	t_lst		*sets_of_paths;
	t_lst		*current_set;
	unsigned	i;
	unsigned	amount_of_sets;
	unsigned	*sets_capacities;
	unsigned	least_value;
}				t_set_search_data;

void			set_rooms_unvisited(t_lst *nodes_list);
void			set_no_path(t_path *path);
void			set_visited_path(t_path *path);

t_room			*visit_links(t_search_data *sd, int weight);
t_room			*visit_preferable_link(t_search_data *sd);
void			search_by_preferable_link(t_search_data *sd);

t_path			*find_the_shortest_path(t_farm *farm,
				void (*modify_farm)(t_path *));

void			find_disjoint_paths(t_farm *farm);
void			set_paths_data(t_lst *set_of_paths);
void			remove_some_links(t_farm *farm);
void			recover_links(t_lst *nodes_list);

void			find_paths(t_farm *farm);

void			best_set_searching(t_farm *farm);
void			move_ants(t_farm *farm);

#endif
