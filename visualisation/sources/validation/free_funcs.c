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

# include "validation.h"

void	free_room(t_input *input)
{
	while (input->room != NULL)
	{
		free(input->room->name);
		free(input->room);
		input->room = input->room->next;
	}
}

void	free_links(t_input *input)
{
	while (input->link != NULL)
	{
		free(input->link);
		input->link = input->link->next;
	}
}

void	free_rooms(t_input *input)
{
	free_room(input);
}

void	free_mem(char **objs, t_input *data)
{
	free_arr(objs);
	free(objs);
	free_room(data);
	free_links(data);
}
