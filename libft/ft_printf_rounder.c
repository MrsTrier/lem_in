/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_rounder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:07:46 by vshelia           #+#    #+#             */
/*   Updated: 2019/12/23 17:08:21 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		rounder(char *fraction, int i)
{
	int j;
	int overflow;

	overflow = 0;
	j = i--;
	if (fraction[i + 1] >= '5' && fraction[i + 1] <= '9')
	{
		if (i >= 0)
			fraction[i] += 1;
		while (i > 0 && fraction[i] == ':')
		{
			fraction[i] = '0';
			i--;
			fraction[i] += 1;
		}
		if (i == -1 || fraction[i] == ':')
		{
			if (i == -1)
				i++;
			fraction[i] = '0';
			overflow = 1;
		}
	}
	fraction[j] = '\0';
	return (overflow);
}

char	*plus_one(char *str)
{
	unsigned long long	nbr;
	char				*new_str;

	if (!str)
		return (NULL);
	nbr = ft_atoull(str);
	nbr++;
	new_str = ft_ulltoa_base(nbr, 10);
	if (*str == '-')
		new_str = add_prefix("-", new_str);
	free(str);
	return (new_str);
}
