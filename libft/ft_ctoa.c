/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:58:53 by vshelia           #+#    #+#             */
/*   Updated: 2019/12/23 15:50:42 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ctoa(char ch)
{
	char *str;

	str = (char *)malloc(sizeof(*str) * 2);
	if (str)
	{
		str[0] = ch;
		str[1] = '\0';
	}
	return (str);
}

static char	*static_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (str)
		ft_memset((void *)str, '\0', size + 1);
	return (str);
}

char		*ft_utfctoa(unsigned int ch)
{
	char	*output;

	if (!(output = static_strnew(4)))
		return (NULL);
	if (ch <= 0x7F)
		output[0] = ch;
	else if (ch <= 0x7FF)
	{
		output[0] = (ch >> 6) | 0xC0;
		output[1] = (ch & 0x3F) | 0x80;
	}
	else if (ch <= 0xFFFF)
	{
		output[0] = (ch >> 12) | 0xE0;
		output[1] = ((ch >> 6) & 0x3F) | 0x80;
		output[2] = (ch & 0x3F) | 0x80;
	}
	else if (ch <= 0x10FFFF)
	{
		output[0] = (ch >> 18) | 0xF0;
		output[1] = ((ch >> 12) & 0x3F) | 0x80;
		output[2] = ((ch >> 6) & 0x3F) | 0x80;
		output[3] = (ch & 0x3F) | 0x80;
	}
	return (output);
}
