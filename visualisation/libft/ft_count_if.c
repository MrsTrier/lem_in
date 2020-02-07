/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:46:33 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/17 15:20:08 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_if(char **tab, t_bool (*f)(const char*))
{
	int count;

	count = 0;
	while (*tab)
		if (f(*tab++) == 1)
			count++;
	return (count);
}
