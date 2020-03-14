/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_non_to_printable.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:04:38 by vshelia           #+#    #+#             */
/*   Updated: 2019/12/23 17:04:46 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*replace_by_definer2(char ch)
{
	if (ch == 25)
		return ("^Y");
	if (ch == 26)
		return ("^Z");
	if (ch == 27)
		return ("^[");
	if (ch == 28)
		return ("^\\");
	if (ch == 29)
		return ("^]");
	if (ch == 30)
		return ("^^");
	if (ch == 31)
		return ("^_");
	return (NULL);
}

static char	*replace_by_definer1(char ch)
{
	if (ch == 13)
		return ("^M");
	if (ch == 14)
		return ("^N");
	if (ch == 15)
		return ("^O");
	if (ch == 16)
		return ("^P");
	if (ch == 17)
		return ("^Q");
	if (ch == 18)
		return ("^R");
	if (ch == 19)
		return ("^S");
	if (ch == 20)
		return ("^T");
	if (ch == 21)
		return ("^U");
	if (ch == 22)
		return ("^V");
	if (ch == 23)
		return ("^W");
	if (ch == 24)
		return ("^X");
	return (replace_by_definer2(ch));
}

static char	*replace_by_definer(char ch)
{
	if (ch == 1)
		return ("^A");
	if (ch == 2)
		return ("^B");
	if (ch == 3)
		return ("^C");
	if (ch == 4)
		return ("^D");
	if (ch == 5)
		return ("^E");
	if (ch == 6)
		return ("^F");
	if (ch == 7)
		return ("^G");
	if (ch == 8)
		return ("^H");
	if (ch == 9)
		return ("	");
	if (ch == 10)
		return ("$");
	if (ch == 11)
		return ("^K");
	if (ch == 12)
		return ("^L");
	return (replace_by_definer1(ch));
}

static char	*replace_np(char *str, int i, const char *printable)
{
	char	*replaced_str;
	char	*temp;

	str[i] = '\0';
	replaced_str = ft_strjoin(str, printable);
	temp = replaced_str;
	replaced_str = ft_strjoin(replaced_str, str + i + 1);
	free_both(temp, str);
	return (replaced_str);
}

char		*non_to_printable(char *str)
{
	int		i;
	char	*printable;

	i = 0;
	while (str && str[i])
	{
		if (str[i] >= 1 && str[i] <= 31)
		{
			printable = replace_by_definer(str[i]);
			str = replace_np(str, i, printable);
		}
		i++;
	}
	return (str);
}
