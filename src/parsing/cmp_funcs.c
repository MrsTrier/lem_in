/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:42:00 by vshelia           #+#    #+#             */
/*   Updated: 2020/03/01 17:36:21 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		cmp_t_rooms(void *a, void *b)
{
	t_room	*room_1;
	t_room	*room_2;

	room_1 = (t_room *)a;
	room_2 = (t_room *)b;
	return (ft_strcmp(room_1->name, room_2->name));
}

int		cmp_str_t_room(void *a, void *b)
{
	char	*name;
	t_room	*room;

	name = (char *)a;
	room = (t_room *)b;
	return (ft_strcmp(name, room->name));
}

int		cmp_t_links(void *a, void *b)
{
	t_link	*link_1;
	t_link	*link_2;

	link_1 = (t_link *)a;
	link_2 = (t_link *)b;
	return (cmp_t_rooms(link_1->room, link_2->room));
}

int		cmp_str_t_link(void *a, void *b)
{
	char	*name;
	t_link	*link;

	name = (char *)a;
	link = (t_link *)b;
	return (cmp_str_t_room(name, link->room));
}

char	handle_command(char *map)
{
	char		command;
	static char	start_exists;
	static char	end_exists;

	command = '\0';
	if (ft_strnequ(map, "##start\n", 8))
	{
		if (start_exists)
			error(ERR_MULT_START, map);
		command = 's';
		start_exists = command;
	}
	else if (ft_strnequ(map, "##end\n", 6))
	{
		if (end_exists)
			error(ERR_MULT_END, map);
		command = 'e';
		end_exists = command;
	}
	return (command);
}
