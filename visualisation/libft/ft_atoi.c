/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:39:18 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/17 19:46:55 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t				i;
	int					sig;
	unsigned long int	result;

	i = 0;
	sig = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sig = -1;
	while ((str[i] != '\0') && ft_isdigit(str[i]))
	{
		if ((result > 922337203685477580 || (result == 922337203685477580 \
		&& (str[i] - '0') > 7)) && sig == 1)
			return (-1);
		else if ((result > 922337203685477580 || (result == 922337203685477580 \
		&& (str[i] - '0') > 8)) && sig == -1)
			return (0);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(result * sig));
}
