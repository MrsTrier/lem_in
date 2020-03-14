/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:03:53 by vshelia           #+#    #+#             */
/*   Updated: 2019/12/23 17:04:06 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*prefix_attacher(t_format *parse, char *source)
{
	char *with_prefix;

	if (*(parse->type) == 'p' || *(parse->type) == 'x')
		with_prefix = ft_strjoin("0x", source);
	else if (*(parse->type) == 'o')
	{
		if (source && *source != '0')
			with_prefix = ft_strjoin("0", source);
		else
			with_prefix = ft_strdup(source);
	}
	else if (*(parse->type) == 'X')
		with_prefix = ft_strjoin("0X", source);
	else if (*(parse->type) == 'b')
		with_prefix = ft_strjoin("b", source);
	else
		with_prefix = NULL;
	if (source)
		free(source);
	return (with_prefix);
}

char	*signed_integer_handler(t_format *parse, va_list arg)
{
	char *output;

	if (parse->length == NULL)
		output = ft_lltoa(va_arg(arg, int));
	else if (*(parse->length) == 'h' && *(parse->length + 1) == 'h')
		output = ft_lltoa((char)va_arg(arg, int));
	else if (*(parse->length) == 'h')
		output = ft_lltoa((short)va_arg(arg, int));
	else if (*(parse->length) == 'l' && *(parse->length + 1) == 'l')
		output = ft_lltoa(va_arg(arg, long long));
	else if (*(parse->length) == 'l')
		output = ft_lltoa(va_arg(arg, long));
	else
		output = NULL;
	return (output);
}

char	*unsigned_integer_handler(t_format *parse, va_list arg, int base)
{
	char *output;

	if (parse->length == NULL)
		output = ft_ulltoa_base((unsigned int)va_arg(arg, int), base);
	else if (*(parse->length) == 'h' && *(parse->length + 1) == 'h')
		output = ft_ulltoa_base((unsigned char)va_arg(arg, int), base);
	else if (*(parse->length) == 'h')
		output = ft_ulltoa_base((unsigned short)va_arg(arg, int), base);
	else if (*(parse->length) == 'l' && *(parse->length + 1) == 'l')
		output = ft_ulltoa_base(va_arg(arg, long long), base);
	else if (*(parse->length) == 'l')
		output = ft_ulltoa_base((unsigned long)va_arg(arg, long), base);
	else
		output = NULL;
	return (output);
}

char	*str_upper(char *source)
{
	int		i;

	if (source)
	{
		i = 0;
		while (source[i])
		{
			if (source[i] >= 'a' && source[i] <= 'z')
				source[i] -= 32;
			i++;
		}
	}
	return (source);
}
