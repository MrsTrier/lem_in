
# include "validation.h"
# include "errors.h"
# include "visualization.h"

t_iteration		*find_iter(t_input *input, int index)
{
	t_iteration	*current;

	current = input->iteration;
	while (current)
	{
		if (current->index == index)
			return (current);
		current = current->next;
	}
	return (NULL);
}
