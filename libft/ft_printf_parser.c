/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:05:58 by vshelia           #+#    #+#             */
/*   Updated: 2019/12/23 17:06:08 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_type(char **format)
{
	(*format)++;
	while (**format)
	{
		if (**format == 'c' || **format == 's' || **format == 'p' ||
			**format == 'd' || **format == 'i' || **format == 'o' ||
			**format == 'u' || **format == 'x' || **format == 'X' ||
			**format == 'f' || **format == 'b' || **format == '%' ||
			**format == 'C' || **format == 'r')
			return (*format);
		(*format)++;
	}
	return (NULL);
}

char	*get_length(char **format)
{
	char *ptr;

	ptr = *format - 1;
	if (*ptr == '%')
		return (NULL);
	else if ((*ptr == 'h' && *(ptr - 1) == 'h') ||
			(*ptr == 'l' && *(ptr - 1) == 'l'))
	{
		*format -= 2;
		return (*format);
	}
	else if (*ptr == 'h' || *ptr == 'l' || *ptr == 'L')
		return (--(*format));
	else
		return (NULL);
}

char	*get_precision(char **format)
{
	char *ptr;

	ptr = *format - 1;
	while (*ptr != '%' && *ptr != '.')
		ptr--;
	if (*ptr == '%')
		return (NULL);
	else
	{
		*format = ptr;
		return (ptr + 1);
	}
}

char	*get_width(char **format)
{
	char *ptr;

	ptr = *format - 1;
	if (*ptr == '%' || *ptr == '-' || *ptr == '+' || *ptr == ' ' ||
		*ptr == '#')
		return (NULL);
	while (*ptr >= '0' && *ptr <= '9')
		ptr--;
	if (*ptr != '*')
		ptr++;
	if (*ptr == '0')
		ptr++;
	if ((*ptr >= '0' && *ptr <= '9') || *ptr == '*')
		return (*format = ptr);
	else
		return (NULL);
}

char	*get_flags(char **format)
{
	char *ptr;

	ptr = *format - 1;
	if (*ptr == '%')
		return (NULL);
	while (*ptr != '%')
		ptr--;
	return (*format = ptr + 1);
}
