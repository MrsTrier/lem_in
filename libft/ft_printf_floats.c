/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_floats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:54:47 by vshelia           #+#    #+#             */
/*   Updated: 2019/12/23 16:55:00 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*add_prefix(const char *prefix, char *source)
{
	char *with_prefix;

	with_prefix = source;
	if (source && *source)
	{
		with_prefix = ft_strjoin(prefix, source);
		free(source);
	}
	return (with_prefix);
}

static char	*fraction_to_str(long double f, char *precision, int *overflow)
{
	char	*fraction;
	int		pr;
	int		i;

	*overflow = 0;
	pr = (precision) ? ft_atoull(precision) : 6;
	fraction = (char *)malloc(sizeof(*fraction) * (++pr + 1));
	if (fraction)
	{
		i = 0;
		while (i < pr)
		{
			f *= 10;
			fraction[i] = '0' + (unsigned int)f;
			f -= (unsigned int)f;
			i++;
		}
		fraction[i] = '\0';
		*overflow = rounder(fraction, i - 1);
	}
	return (fraction);
}

static char	*check_value(long double f)
{
	char	*bad_value;

	if (f != f)
		bad_value = ft_strdup("nan");
	else if (f == 1.0 / 0.0)
		bad_value = ft_strdup("+inf");
	else if (f == -1.0 / 0.0)
		bad_value = ft_strdup("-inf");
	else
		bad_value = NULL;
	return (bad_value);
}

char		*ft_ldtoa(long double f, char *precision)
{
	char	*output;
	char	*integer_part;
	char	*float_part;
	int		flag;

	if ((output = check_value(f)))
		return (output);
	flag = 0;
	if (f < 0)
	{
		f = -f;
		flag = 1;
	}
	integer_part = ft_ulltoa_base((unsigned long long)f, 10);
	if (flag)
		integer_part = add_prefix("-", integer_part);
	f -= (unsigned long long)f;
	float_part = add_prefix(".", fraction_to_str(f, precision, &flag));
	if (flag)
		integer_part = plus_one(integer_part);
	output = ft_strjoin(integer_part, float_part);
	free_both(integer_part, float_part);
	return (output);
}

char		*float_handler(t_format *parse, va_list arg)
{
	char	*output;
	char	*temp;

	if (parse->length == NULL || *(parse->length) == 'l')
		output = ft_ldtoa(va_arg(arg, double), parse->precision);
	else if (*(parse->length) == 'L')
		output = ft_ldtoa(va_arg(arg, long double), parse->precision);
	else
		output = NULL;
	if (output && flag_exists(parse->flags, '#') && !ft_strchr(output, '.'))
	{
		temp = output;
		output = ft_strjoin(output, ".");
		free(temp);
	}
	return (output);
}
