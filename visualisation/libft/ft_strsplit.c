/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:08:30 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/17 11:48:15 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wrdcount(char const *s, char c, int *j)
{
	int i;
	int wrd;

	i = 0;
	wrd = 0;
	while (s[*j] == c && s[*j])
		*j += 1;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			wrd++;
			i++;
		}
		else
			i++;
	}
	return (wrd);
}

static char		*ft_word(char const *s, int *i, int c)
{
	int		j;
	int		len;
	char	*fr;
	int		cp;

	j = 0;
	cp = *i;
	len = 0;
	while (s[*i] != '\0' && s[*i] != c)
	{
		*i += 1;
		len++;
	}
	if (!(fr = (char *)malloc(len + 1)))
		return (NULL);
	while (s[cp] != c && s[cp])
		fr[j++] = s[cp++];
	fr[j] = '\0';
	while (s[cp] == c)
		cp++;
	*i = cp;
	return (fr);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		wrd;
	int		j;
	char	**fresh;

	wrd = 0;
	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	wrd = ft_wrdcount(s, c, &i);
	if (!(fresh = (char **)malloc(sizeof(*fresh) * (wrd + 1))))
		return (NULL);
	while (j < wrd)
	{
		if (!(fresh[j++] = ft_word(s, &i, c)))
		{
			while (j >= 0)
				ft_memdel((void *)fresh[j--]);
			ft_memdel((void *)fresh);
			return (NULL);
		}
	}
	fresh[j] = NULL;
	return (fresh);
}
