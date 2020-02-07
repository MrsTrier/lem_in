/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:29:30 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/17 19:47:17 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_len(int cp)
{
	int i;

	i = 0;
	while (cp >= 10)
	{
		cp = cp / 10;
		i++;
	}
	return (i + 1);
}

static char	*ft_fill(int i, int n, int neg, char *res)
{
	res[i] = '\0';
	i--;
	while (n >= 10)
	{
		res[i] = (char)((n % 10) + '0');
		n /= 10;
		i--;
	}
	res[i--] = (char)((n % 10) + '0');
	if (neg)
		res[i] = 45;
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		neg;

	neg = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		n *= -1;
		neg = 1;
	}
	len = ft_nb_len(n) + neg;
	if (!(res = (char *)malloc(len + 1)))
		return (NULL);
	ft_fill(len, n, neg, res);
	return (res);
}
