
# include "validation.h"
# include "errors.h"
# include <stdio.h>


void	check_params(char *ant_room, t_input *data)
{
	char		**objs;

	objs = ft_strsplit(ant_room, '-');
	if (!is_int(objs[0]))
		error_found(ERR_INPUT);
	if (ft_atoi(objs[0]) > data->ants_num)
		error_found(ERR_INPUT);
	if (!room_exists(data->room, objs[1]))
		error_found(ERR_INPUT);
	free_arr(objs);
	free(objs);
}

void	save_iteration(t_input *data, char *res)
{

}


void	is_res_right(char *res, t_input *data)
{
	char		**objs;
	char		*ant_room;
	int 		i;

	i = 0;
	objs = ft_strsplit(res, ' ');
	while (objs[i] != NULL)
	{
		ant_room = (objs[i] + 1);
		if (objs[i][0] != 'L')
			error_found(ERR_INPUT);
		check_params(ant_room, data);
		i++;
		save_iteration(data, res);
	}
	free_arr(objs);
	free(objs);
}

void	validate_result(char *res, t_input *data)
{
	char		**objs;
	int 		i;

	i = 0;
	objs = ft_strsplit(res, '\n');
	while (objs[i] != NULL)
	{
		is_res_right(objs[i], data);
		i++;
	}
	free_arr(objs);
	free(objs);
}
