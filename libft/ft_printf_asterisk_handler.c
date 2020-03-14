/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_asterisk_handler.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:53:50 by vshelia           #+#    #+#             */
/*   Updated: 2019/12/23 16:54:21 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ignore_minus(char *precision)
{
	if (precision && *precision == '-')
	{
		free(precision);
		return (NULL);
	}
	return (precision);
}

int			handle_asterisk(t_format *parse, va_list arg)
{
	int		code;

	code = 0;
	if (parse->width && *(parse->width) == '*')
	{
		parse->width = ft_lltoa(va_arg(arg, int));
		code = 1;
	}
	if (parse->precision && *(parse->precision) == '*')
	{
		parse->precision = ignore_minus(ft_lltoa(va_arg(arg, int)));
		code = (code) ? 3 : 2;
	}
	if (parse->width && *(parse->width) == '-')
	{
		parse->flags = (parse->flags) ? ft_strjoin("-", parse->flags)
			: ft_strdup("-");
		if (code == 1)
			code = 11;
		else if (code == 3)
			code = 33;
	}
	return (code);
}

void		free_asterisk(t_format *parse, int code)
{
	if (code)
	{
		if ((code == 1 || code == 11) && parse->width)
			free(parse->width);
		else if (code == 2 && parse->precision)
			free(parse->precision);
		else if ((code == 3 || code == 33)
				&& (parse->width || parse->precision))
		{
			if (parse->width)
				free(parse->width);
			if (parse->precision)
				free(parse->precision);
		}
		if ((code == 11 || code == 33) && parse->flags)
			free(parse->flags);
	}
}
