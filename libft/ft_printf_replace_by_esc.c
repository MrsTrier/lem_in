/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_replace_by_esc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:06:41 by vshelia           #+#    #+#             */
/*   Updated: 2019/12/23 17:07:02 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*replace_by(char *string, char *start, const char *color)
{
	char	*replaced_str;
	char	*temp;

	*start = '\0';
	replaced_str = ft_strjoin(string, color);
	if (!replaced_str)
		return (NULL);
	while (*start != '}')
		start++;
	temp = replaced_str;
	replaced_str = ft_strjoin(replaced_str, start + 1);
	free(temp);
	free(string);
	return (replaced_str);
}

char		*replace_by_esc(char *string)
{
	char *start;

	start = string;
	while (start)
	{
		if ((start = ft_strstr(string, "{eoc}")))
			string = replace_by(string, start, RESET);
		else if ((start = ft_strstr(string, "{black}")))
			string = replace_by(string, start, F_BLACK);
		else if ((start = ft_strstr(string, "{red}")))
			string = replace_by(string, start, F_RED);
		else if ((start = ft_strstr(string, "{green}")))
			string = replace_by(string, start, F_GREEN);
		else if ((start = ft_strstr(string, "{yellow}")))
			string = replace_by(string, start, F_YELLOW);
		else if ((start = ft_strstr(string, "{blue}")))
			string = replace_by(string, start, F_BLUE);
		else if ((start = ft_strstr(string, "{magenta}")))
			string = replace_by(string, start, F_MAGENTA);
		else if ((start = ft_strstr(string, "{cyan}")))
			string = replace_by(string, start, F_CYAN);
		else if ((start = ft_strstr(string, "{bold}")))
			string = replace_by(string, start, BOLD);
	}
	return (string);
}
