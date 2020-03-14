/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:36:41 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/04 12:36:45 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"

void	free_room(t_input *input)
{
	t_room	*next_room;

	if (input)
	{
		while (input->room != NULL)
		{
			next_room = input->room->next;
			free(input->room->name);
			free(input->room);
			input->room = next_room;
		}
	}
}

void	free_ant(t_iteration *input)
{
	t_ant	*next_ant;

	if (input)
	{
		while (input->ant != NULL)
		{
			next_ant = input->ant->next;
			free(input->ant);
			input->ant = next_ant;
		}
	}
}

void	free_iter(t_input *input)
{
	t_iteration	*next_iter;

	if (input)
	{
		while (input->iteration != NULL)
		{
			next_iter = input->iteration->next;
			free_ant(input->iteration);
			free(input->iteration);
			input->iteration = next_iter;
		}
	}
}

void	free_links(t_input *input)
{
	t_link	*next_link;

	while (input->link != NULL)
	{
		next_link = input->link->next;
		free(input->link);
		input->link = next_link;
	}
}

void	free_mem(char **objs, t_input *data)
{
	ft_free_strsplit(objs);
	free(objs);
	free_room(data);
	free_links(data);
}
