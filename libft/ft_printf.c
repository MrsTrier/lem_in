/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:50:29 by vshelia           #+#    #+#             */
/*   Updated: 2020/01/23 18:21:42 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int			ft_fprintf(int fd, const char *format, ...)
{
	va_list	arg;
	char	*format_dup;
	int		printed;

	va_start(arg, format);
	format_dup = ft_strdup(format);
	format_dup = replace_by_esc(format_dup);
	if (!format_dup)
		return (-1);
	printed = parser(fd, format_dup, arg);
	free(format_dup);
	va_end(arg);
	return (printed);
}

int			ft_printf(const char *format, ...)
{
	va_list	arg;
	char	*format_dup;
	int		printed;

	va_start(arg, format);
	format_dup = ft_strdup(format);
	format_dup = replace_by_esc(format_dup);
	if (!format_dup)
		return (-1);
	printed = parser(1, format_dup, arg);
	free(format_dup);
	va_end(arg);
	return (printed);
}

int			parser(int fd, char *format, va_list arg)
{
	t_format	parse;
	int			printed;

	printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (!(parse.type = get_type(&format)))
				return (-1);
			parse.length = get_length(&format);
			parse.precision = get_precision(&format);
			parse.width = get_width(&format);
			parse.flags = get_flags(&format);
			printed += convert_n_print(fd, &parse, arg) - 1;
			format = parse.type;
		}
		else
			write(fd, format, 1);
		printed++;
		format++;
	}
	return (printed);
}

static int	printer(int fd, t_format *parse, const char *output)
{
	size_t	printed;

	printed = -1;
	if (output)
	{
		if (*(parse->type) == '0')
		{
			if (*output == '\0')
				printed = write(fd, "", 1);
			else if (flag_exists(parse->flags, '-'))
			{
				write(fd, "", 1);
				printed = write(fd, output, ft_strlen(output) - 1) + 1;
			}
			else
			{
				printed = write(fd, output, ft_strlen(output) - 1) + 1;
				write(fd, "", 1);
			}
		}
		else
			printed = write(fd, output, ft_strlen(output));
	}
	return (printed);
}

int			convert_n_print(int fd, t_format *parse, va_list arg)
{
	char	*output;
	size_t	printed;
	int		code;

	printed = -1;
	code = handle_asterisk(parse, arg);
	output = operation_definer(parse, arg);
	if (output)
	{
		output = apply_precision(parse, output);
		output = apply_width(parse, output);
		output = apply_flags(parse, output);
		printed = printer(fd, parse, output);
		free_asterisk(parse, code);
		free(output);
	}
	return (printed);
}
