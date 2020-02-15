# include "validation.h"
# include "errors.h"

void		save_iteration(t_iteration **iter, t_iteration *new_iter)
{
	t_iteration	**head;
	t_iteration	*pr;

	pr = *iter;
	head = iter;
	if (*head)
	{
		while (pr->next != NULL)
		{
			pr = pr->next;
			new_iter->index += 1;
		}
	}
	if (!*head)
	{
		*head = new_iter;
		(*head)->next = NULL;
	}
	else
	{
		pr->next = new_iter;
		new_iter->index += 1;
		pr->next->next = NULL;
	}
}
