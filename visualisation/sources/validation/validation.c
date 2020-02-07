/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:37:34 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/04 12:37:36 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

bool		room_exists(t_room *roomlst, char *name)
{
	if (roomlst)
	{
		while (roomlst->next != NULL)
		{
			if (!(ft_strcmp(roomlst->name, name)))
				return (true);
			roomlst = roomlst->next;
		}
		if (!(ft_strcmp(roomlst->name, name)))
			return (true);
	}
	return (false);
}

bool	duplicated_coords(t_room *roomlst, int x, int y)
{

	if (roomlst)
	{
		while (roomlst->next != NULL)
		{
			if ((roomlst->x == x) && (roomlst->y == y))
				return (true);
			roomlst = roomlst->next;
		}
		if ((roomlst->x == x) && (roomlst->y == y))
			return (true);
	}
	return (false);

}
