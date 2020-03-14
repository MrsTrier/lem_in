/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_farm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:48:00 by vshelia           #+#    #+#             */
/*   Updated: 2020/03/01 17:29:45 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <unistd.h>
#include <limits.h>

void			set_number_of_ants(t_farm *farm, char **map)
{
	char			*str;
	char			*newline;
	unsigned long	number;

	str = *map;
	if (*str == '\0' || *str == '\n' || *str == '0')
		error(ERR_ANT_0, *map);
	else if (*str == '+' || *str == '-')
		error(ERR_ANT_SIGN, *map);
	if (!(newline = ft_strchr(str, '\n')))
		error(ERR_ANT_LAST_STR, *map);
	if (newline - str > 10)
		error(ERR_ANT_MANY_SYMB, *map);
	while (str < newline)
		if (!ft_isdigit(*str++))
			error(ERR_ANT_NOT_DIGIT, *map);
	number = (unsigned long)ft_atoull(*map);
	if (number > INT_MAX)
		error(ERR_ANT_GREATER_MAX, *map);
	farm->number_of_ants = (unsigned int)number;
	*map = newline + 1;
}

char			*find_dash_line(char *str)
{
	char	*dash;

	dash = str;
	while ((dash = ft_strchr(dash, '-')))
	{
		while (*(dash - 1) != '\n')
			dash--;
		if (*dash == '#')
		{
			if (!(dash = ft_strchr(dash, '\n')))
				error(ERR_ROOM_NO_DASH, NULL);
			dash++;
		}
		else
			break ;
	}
	if (!dash || dash == str)
		error(ERR_ROOM_NO_DASH, NULL);
	return (dash);
}

unsigned int	set_room_coordinate(char *start, char *end)
{
	char			*str;
	unsigned long	coordinate;

	if (end - start > 10)
		error(ERR_ROOM_LARGE_COORD, start);
	str = start;
	while (str < end)
		if (!ft_isdigit(*str++))
			error(ERR_ROOM_ND_C, start);
	coordinate = (unsigned long)ft_atoull(start);
	if (coordinate > INT_MAX)
		error(ERR_ROOM_GRTR_MAX, start);
	return ((unsigned int)coordinate);
}

char			*create_room_name(char *parse_str, char *str_end,
				char **space_1, char **space_2)
{
	char	*str;

	*space_1 = strchr_until(parse_str, ' ', str_end);
	*space_2 = strchr_until(*space_1 + 1, ' ', str_end);
	if (*space_2 - *space_1 == 1 || str_end - *space_2 == 1 ||
			*(*space_2 + 1) == ' ' || *(str_end - 1) == ' ')
		error(ERR_ROOM_WRONG_SPACES, parse_str);
	str = parse_str;
	if (*str == 'L')
		error(ERR_ROOM_L, parse_str);
	if (*str == ' ')
		error(ERR_ROOM_SPACE, parse_str);
	while (str < *space_1)
		if (!ft_isprint(*str++))
			error(ERR_ROOM_NON_PRIN, parse_str);
	str = ft_strsub(parse_str, 0, *space_1 - parse_str);
	if (!str)
		ft_error("Error in memory allocation (create_room_name)");
	return (str);
}

void			check_duplicate_coordinates(t_lst *nodes_list)
{
	t_lst	*temp;
	t_room	*room_1;
	t_room	*room_2;

	while (nodes_list->next)
	{
		room_1 = (t_room *)(((t_avl_tree *)(nodes_list->content))->content);
		temp = nodes_list->next;
		while (temp)
		{
			room_2 = (t_room *)(((t_avl_tree *)(temp->content))->content);
			if (room_1->coord_x == room_2->coord_x
					&& room_1->coord_y == room_2->coord_y)
				error(ERR_ROOM_DUP_COORDS, NULL);
			temp = temp->next;
		}
		nodes_list = nodes_list->next;
	}
}
