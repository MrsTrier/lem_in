/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formatting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:55:34 by vshelia           #+#    #+#             */
/*   Updated: 2019/12/23 16:59:36 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*apply_precision_int(char *source, int pr, t_format *parse)
{
	char	*with_precisn;
	char	*temp;

	with_precisn = (*source == '-') ? source + 1 : source;
	if (number_is_zero(source) && parse->precision && pr == 0)
		*source = '\0';
	else if ((pr -= ft_strlen(with_precisn)) > 0)
	{
		if (!(with_precisn = (char *)malloc(sizeof(*with_precisn) * (pr + 1))))
			return (source);
		ft_memset((void *)with_precisn, '0', pr);
		with_precisn[pr] = '\0';
		if (*source == '-')
			with_precisn = add_prefix("-", with_precisn);
		temp = with_precisn;
		with_precisn = (*source == '-') ? ft_strjoin(with_precisn, source + 1)
			: ft_strjoin(with_precisn, source);
		free_both(temp, source);
	}
	else
		with_precisn = source;
	if (flag_exists(parse->flags, '#')
			&& (!number_is_zero(with_precisn) || *(parse->type) == 'o'))
		with_precisn = prefix_attacher(parse, with_precisn);
	return (with_precisn);
}

static char	*apply_precision_str(char *source, int pr)
{
	int len;

	len = ft_strlen(source);
	if (pr < len)
		source[pr] = '\0';
	return (source);
}

char		*apply_precision(t_format *parse, char *source)
{
	char	*with_precision;
	int		pr;

	with_precision = source;
	pr = ft_atoull(parse->precision);
	if (*(parse->type) == 'd' || *(parse->type) == 'i' || *(parse->type) == 'o'
			|| *(parse->type) == 'u' || *(parse->type) == 'x' ||
			*(parse->type) == 'X' || *(parse->type) == 'b')
		with_precision = apply_precision_int(source, pr, parse);
	else if (*(parse->type) == 's' && parse->precision)
		with_precision = apply_precision_str(source, pr);
	return (with_precision);
}

static char	*attach_to_side(t_format *parse, char *source, char *new)
{
	char	*with_width;

	if (flag_exists(parse->flags, '-'))
		with_width = ft_strjoin(source, new);
	else
	{
		if (*source == '-' && *new == '0')
		{
			*source = '0';
			*new = '-';
		}
		with_width = ft_strjoin(new, source);
	}
	free(new);
	free(source);
	return (with_width);
}

char		*apply_width(t_format *parse, char *source)
{
	char	*with_width;
	int		w;

	if (!source)
		return (NULL);
	w = ft_atoull(parse->width);
	if (*(parse->type) == 'c' && *source == '\0')
		*(parse->type) = '0';
	if (!((w -= ft_strlen(source)) > 0))
		return (source);
	if (!(with_width = (char *)malloc(sizeof(*with_width) * (w + 1))))
		return (source);
	if (flag_exists(parse->flags, '0') && !(flag_exists(parse->flags, '-'))
			&& (((*(parse->type) == 'f') &&
					((*source == '-' && *(source + 1) != 'i') ||
						(*source >= '0' && *source <= '9')))
				|| !(parse->precision)))
		ft_memset((void *)with_width, '0', w);
	else
		ft_memset((void *)with_width, ' ', w);
	with_width[w] = '\0';
	with_width = attach_to_side(parse, source, with_width);
	return (with_width);
}
