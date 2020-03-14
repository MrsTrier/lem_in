/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_farm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 21:42:00 by vshelia           #+#    #+#             */
/*   Updated: 2020/03/04 13:25:42 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_room	*create_room(char *parse_str, char *str_end, char *position,
				t_farm *farm)
{
	t_room	*new_room;
	char	*name;
	char	*space_1;
	char	*space_2;

	name = create_room_name(parse_str, str_end, &space_1, &space_2);
	new_room = (t_room *)ft_memalloc(sizeof(*new_room));
	if (new_room)
	{
		new_room->name = name;
		if (*position)
		{
			new_room->position = *position;
			if (*position == 's')
				farm->start_room = new_room;
			else
				farm->end_room = new_room;
			*position = '\0';
		}
		new_room->coord_x = set_room_coordinate(space_1 + 1, space_2);
		new_room->coord_y = set_room_coordinate(space_2 + 1, str_end);
	}
	else
		ft_error("Error in memory allocation (create_room)");
	return (new_room);
}

static void		build_rooms(t_farm *farm, char **map)
{
	t_room	*room;
	char	*dash;
	char	*newline;
	char	room_position;

	room_position = '\0';
	dash = find_dash_line(*map);
	while (*map < dash)
	{
		newline = ft_strchr(*map, '\n');
		if (**map == '#')
			room_position = handle_command(*map);
		else if (farm->number_of_rooms < ROOMS_LIMIT)
		{
			room = create_room(*map, newline, &room_position, farm);
			if (!ft_avl_tree_search(farm->farm, room, cmp_t_rooms))
				farm->farm = ft_avl_tree_insert(farm->farm, room, cmp_t_rooms);
			else
				error(ERR_ROOM_NON_UNIQUE, *map);
			farm->number_of_rooms++;
		}
		else
			error(ERR_ROOM_LIMIT, *map);
		*map = newline + 1;
	}
}

static void		create_link(t_room *room, t_room *link_to_save, char *str)
{
	t_link	*link;

	if (room->amount_of_links == LINKS_LIMIT)
		error(ERR_LINK_LIMIT, str);
	if (ft_strequ(room->name, link_to_save->name))
		error(ERR_LINK_SAME, str);
	if (ft_avl_tree_search(room->links, link_to_save->name, cmp_str_t_link))
		error(ERR_LINK_EXIST, str);
	link = (t_link *)ft_memalloc(sizeof(*link));
	if (link)
	{
		link->room = link_to_save;
		link->edge_weight = 1;
		room->links = ft_avl_tree_insert(room->links, link, cmp_t_links);
		room->amount_of_links++;
	}
	else
		ft_error("Error in memory allocation (create_link)");
}

static void		build_links(t_avl_tree *tree, char **map)
{
	char		*newline;
	char		*names[2];
	t_avl_tree	*node1;
	t_avl_tree	*node2;

	while (**map)
	{
		newline = ft_strchr(*map, '\n');
		if (**map == '#')
			handle_command(*map);
		else
		{
			parse_links_names(*map, newline, names);
			node1 = ft_avl_tree_search(tree, names[0], cmp_str_t_room);
			node2 = ft_avl_tree_search(tree, names[1], cmp_str_t_room);
			free_both(names[0], names[1]);
			if (!node1 || !node2)
				error(ERR_LINK_NOT_EXIST, *map);
			create_link((t_room *)(node1->content), (t_room *)(node2->content),
				*map);
			create_link((t_room *)(node2->content), (t_room *)(node1->content),
				*map);
		}
		*map = (newline) ? newline + 1 : ft_strchr(*map, '\0');
	}
}

void			build_farm(t_farm *farm)
{
	char	*map;

	ft_bzero(farm, sizeof(*farm));
	farm->map = read_fd(0);
	g_map = farm->map;
	if (farm->map == NULL)
		error(ERR_EMPTY_INPUT, NULL);
	map = farm->map;
	while (*map == '#')
	{
		handle_command(map);
		if (!(map = ft_strchr(map, '\n')))
			error(ERR_ONLY_COMMENTS, NULL);
		map++;
	}
	set_number_of_ants(farm, &map);
	build_rooms(farm, &map);
	build_links(farm->farm, &map);
	if (farm->start_room == NULL)
		error(ERR_NO_START, NULL);
	if (farm->end_room == NULL)
		error(ERR_NO_END, NULL);
	farm->nodes_list = postorder_list_of_nodes(farm->farm);
	check_duplicate_coordinates(farm->nodes_list);
	create_links_nodes_lists(farm->nodes_list);
}
