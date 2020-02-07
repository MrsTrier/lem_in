# include "validation.h"
# include "errors.h"

void	check_for_ant(char *input, t_input *data)
{
	if (data->flag & ANT)
		error_found(ERR_INPUT);
	else
		data->flag |= ANT;
	data->ants_num = ft_atoi(input);
}
