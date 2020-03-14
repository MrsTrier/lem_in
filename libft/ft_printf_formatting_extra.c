/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formatting_extra.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:00:25 by vshelia           #+#    #+#             */
/*   Updated: 2019/12/23 17:01:00 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*insert_char(const char *ch, char *src, t_format *parse)
{
	char	*temp;
	int		i;

	temp = src;
	i = 0;
	while (src[i] == ' ')
		i++;
	if (src[i] == '-' ||
			(!(src[i] >= '0' && src[i] <= '9') && src[i]))
		return (src);
	if (!src[i] && flag_exists(parse->flags, '-'))
		*src = *ch;
	else if (src[i] == '0' && src[i + 1] && flag_exists(parse->flags, '0')
			&& (*(parse->type) == 'f' || !(parse->precision)))
		src[i] = *ch;
	else if (i > 0)
		src[i - 1] = *ch;
	else if (i == 0)
	{
		src = ft_strjoin(ch, src);
		free(temp);
		if ((temp = ft_strrchr(src, ' ')) && *(temp + 1) == '\0')
			*temp = '\0';
	}
	return (src);
}

int			number_is_zero(const char *str)
{
	while (*str)
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}

int			flag_exists(char *flags, char flag)
{
	int i;

	if (flags)
	{
		i = 0;
		while (flags[i] == '-' || flags[i] == '+' || flags[i] == ' ' ||
				flags[i] == '0' || flags[i] == '#')
		{
			if (flags[i] == flag)
				return (1);
			i++;
		}
	}
	return (0);
}

static void	replace_x(char *str)
{
	char	*ptr_x;
	char	*ptr_zero;

	ptr_x = ft_strchr(str, 'x');
	if (!ptr_x)
		ptr_x = ft_strchr(str, 'X');
	if (ptr_x)
	{
		ptr_zero = ft_strchr(str, '0');
		ptr_zero++;
		if (ptr_x - ptr_zero > 0)
		{
			*ptr_zero = *ptr_x;
			*ptr_x = '0';
		}
	}
}

char		*apply_flags(t_format *parse, char *source)
{
	char	*plus_or_space;

	if (!source)
		return (NULL);
	plus_or_space = NULL;
	if (flag_exists(parse->flags, '+'))
		plus_or_space = "+";
	else if (flag_exists(parse->flags, ' '))
		plus_or_space = " ";
	if (plus_or_space && (*(parse->type) == 'f'
				|| *(parse->type) == 'd' || *(parse->type) == 'i'))
		source = insert_char(plus_or_space, source, parse);
	if (flag_exists(parse->flags, '#') && flag_exists(parse->flags, '0'))
		replace_x(source);
	return (source);
}
