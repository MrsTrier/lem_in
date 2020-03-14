/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:17:20 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/12 14:26:52 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int i;
	int i_sqr;

	if (nb == 1)
		return (1);
	else if (nb < 4)
		return (0);
	i = 2;
	i_sqr = i * i;
	while (i_sqr <= nb)
	{
		if (i_sqr < 0)
			break ;
		else if (i_sqr == nb)
			return (i);
		i++;
		i_sqr = i * i;
	}
	return (0);
}
