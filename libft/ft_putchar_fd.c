/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:13:29 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/11 21:24:39 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	unsigned char ch;
	unsigned char octet1;
	unsigned char octet2;

	ch = (unsigned char)c;
	if (ch > 127)
	{
		octet1 = (ch >> 6) | 192;
		octet2 = (ch & 63) | 128;
		write(fd, &octet1, 1);
		write(fd, &octet2, 1);
	}
	else
		write(fd, &ch, 1);
}
