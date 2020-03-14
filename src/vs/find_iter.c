/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:20:43 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"

t_iteration		*find_iter(t_input *input, int index)
{
	t_iteration	*current;

	if (input->iteration != NULL)
		current = input->iteration;
	else
		return (NULL);
	while (current)
	{
		if (current->index == index)
			return (current);
		current = current->next;
	}
	return (NULL);
}
