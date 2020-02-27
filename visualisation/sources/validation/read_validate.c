/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:37:00 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"
#include "vis_errors.h"

void		check_for_errors(char *input, char obj, t_input *data)
{
	char	**objs;

	if (obj == 't')
		check_for_type(input, data);
	else if (obj == 'a')
		check_for_ant(input, data);
	else
	{
		if (obj == 'r')
			check_for_room(input, data, &objs);
		if (obj == 'l')
			check_for_link(input, data, &objs);
		ft_free_strsplit(objs);
	}
}

void		initialize_vars(t_input *input, int *i, char ***objs, char *line)
{
	*i = 0;
	*objs = ft_strsplit(line, '\n');
	input->ants_num = -1;
	input->rooms_num = -1;
	input->start_room = -1;
	input->end_room = -1;
	input->flag = 0b01100000;
	input->room = NULL;
	input->link = NULL;
	input->iteration = NULL;
	input->iter_num = 0;
}

void		validate_read(char *input, t_input *data)
{
	char	**objs;
	int		i;

	initialize_vars(data, &i, &objs, input);
	while (objs[i] != NULL && (objs[i][0] != '\n'))
	{
		if (!(objs[i]))
			is_input_corect(data);
		if (is_ant_num(objs[i]))
			check_for_errors(objs[i], 'a', data);
		else if (is_room(objs[i]))
			check_for_errors(objs[i], 'r', data);
		else if (is_comment(objs[i]))
			;
		else if (is_type_of_room(objs[i]))
			check_for_errors(objs[i], 't', data);
		else if (is_link(objs[i]))
			check_for_errors(objs[i], 'l', data);
		else
			error_found(ERR_INPUT);
		i++;
	}
	is_input_corect(data);
	ft_free_strsplit(objs);
}

void		split_input(char **map, char **res)
{
	int		i;

	i = 0;
	if (ft_strlen(*map) >= 3)
		while ((!(((*map)[i] == '\n') && ((*map)[i + 1]) == '\n'))
										&& (*map)[i + 2] != '\0')
			i++;
	(*map)[i + 1] = '\0';
	*res = (*map) + i + 2;
	if ((*res)[0] != 'L')
		error_found(ERR_INPUT);
}

void		read_validate(char **res, t_input *data, int fd)
{
	char	*map;

	map = read_fd(fd);
	if (map != NULL)
	{
		split_input(&map, res);
		validate_read(map, data);
		validate_result(*res, data);
		free(map);
	}
	else
		error_found(ERR_INPUT);
}
