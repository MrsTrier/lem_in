/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_operation_definer.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:05:12 by vshelia           #+#    #+#             */
/*   Updated: 2019/12/23 17:05:21 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*operation_definer1(t_format *parse, va_list arg)
{
	char *output;

	(void)arg;
	if (*(parse->type) == '%')
		output = ft_ctoa('%');
	else if (*(parse->type) == 'C')
		output = ft_utfctoa(va_arg(arg, int));
	else if (*(parse->type) == 'r')
		output = non_to_printable(ft_strdup(va_arg(arg, char *)));
	else
		output = NULL;
	return (output);
}

char		*operation_definer(t_format *parse, va_list arg)
{
	char *output;

	if (*(parse->type) == 'c')
		output = ft_ctoa(va_arg(arg, int));
	else if (*(parse->type) == 's')
		output = string_assignment(ft_strdup(va_arg(arg, char *)));
	else if (*(parse->type) == 'p')
		output = prefix_attacher(parse, ft_ulltoa_base(va_arg(arg, long), 16));
	else if (*(parse->type) == 'd' || *(parse->type) == 'i')
		output = signed_integer_handler(parse, arg);
	else if (*(parse->type) == 'o')
		output = unsigned_integer_handler(parse, arg, 8);
	else if (*(parse->type) == 'u')
		output = unsigned_integer_handler(parse, arg, 10);
	else if (*(parse->type) == 'x')
		output = unsigned_integer_handler(parse, arg, 16);
	else if (*(parse->type) == 'X')
		output = str_upper(unsigned_integer_handler(parse, arg, 16));
	else if (*(parse->type) == 'b')
		output = unsigned_integer_handler(parse, arg, 2);
	else if (*(parse->type) == 'f')
		output = float_handler(parse, arg);
	else
		output = operation_definer1(parse, arg);
	return (output);
}
