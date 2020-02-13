# include "validation.h"
# include "errors.h"
# include <stdio.h>

t_room		*find_room(t_input *input, char *name)
{
	t_room	*current;

	current = input->room;
	while (current)
	{
		if (!ft_strcmp(current->name, name))
			return (current);
		current = current->next;
	}
	return (NULL);
}
