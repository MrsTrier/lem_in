/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_objtype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:37:34 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/04 12:37:36 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "validation.h"

bool	is_room(char *line)
{
	char	**objs;
	bool	res;
	int 	objs_num;

	res = false;
	objs = ft_strsplit(line, ' ');
	objs_num = count_objs(objs);
	if (objs_num != 3 || ft_strchr(objs[0], '-'))
		res = false;
	else
	{
		if (!objs[0][0] || !objs[0] || objs[0][0] == 'L')
			res = false;
		else if (!(objs[1] && is_int(objs[1])))
			res = false;
		else if (!(objs[2] && is_int(objs[2])))
			res = false;
		else
			res = true;
	}
	free_arr(objs);
	free(objs);
	return (res);
}

bool	is_link(char *line)
{
	char	**objs;
	bool	res;

	res = false;
	if (ft_strchr(line, '-'))
	{
		objs = ft_strsplit(line, '-');
		if (count_objs(objs) == 2)
			res = true;
		free_arr(objs);
		free(objs);
	}
	return (res);
}

bool	is_ant_num(char *line)
{
	int		ant_num;

	if (ft_strchr(line, ' '))
		return (false);
	ant_num = is_int(line);
	if (ant_num)
		return (true);
	return (false);
}


bool	is_type_of_room(char *line)
{
	if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
		return (true);
	return (false);
}

bool	is_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (true);
	return (false);
}
