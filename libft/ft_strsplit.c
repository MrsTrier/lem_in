/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:35:06 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/20 22:21:00 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	delimiter_passer(char const **s, char c)
{
	while (**s == c)
		(*s)++;
}

static int	str_arr_len(char const *s, char c)
{
	int words;

	words = 0;
	while (*s)
	{
		delimiter_passer(&s, c);
		if (*s && *s != c)
			words++;
		while (*s && *s != c)
			s++;
		if (*s)
			s++;
	}
	return (words);
}

static int	word_len(char const **s, char c)
{
	int len;

	len = 0;
	delimiter_passer(s, c);
	while (**s && **s != c)
	{
		len++;
		(*s)++;
	}
	return (len);
}

static void	*str_arr_del(char **str_arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_strdel(str_arr + i);
		i++;
	}
	free(str_arr);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str_arr;
	int		words;
	int		word;
	int		i;

	str_arr = NULL;
	if (!s)
		return (NULL);
	words = str_arr_len(s, c);
	str_arr = (char **)malloc(sizeof(*str_arr) * (words + 1));
	if (str_arr)
	{
		i = 0;
		while (i < words)
		{
			word = word_len(&s, c);
			str_arr[i] = ft_strnew(word);
			if (str_arr[i])
				(void)ft_strncpy(str_arr[i++], s - word, word);
			else
				return (str_arr_del(str_arr, i));
		}
		str_arr[i] = NULL;
	}
	return (str_arr);
}
