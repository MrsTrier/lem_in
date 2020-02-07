
# include "validation.h"
# include "errors.h"

void	set_obj_flags(char *line, t_input *data)
{
	if (line[2] == 's')
	{
		data->start_room = -1;
		data->flag |= START;
		data->flag &= ~START_ROOM;
	}
	else if (line[2] == 'e')
	{
		data->end_room = -1;
		data->flag |= END;
		data->flag &= ~END_ROOM;
	}
}

void	check_for_type(char *input, t_input *data)
{
	if ((data->flag & START) && !(data->flag & START_ROOM))
		error_found(ERR_INPUT);
	else if ((data->flag & END) && !(data->flag & END_ROOM))
		error_found(ERR_INPUT);
	else
		set_obj_flags(input, data);
}
