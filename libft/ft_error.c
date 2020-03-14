/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:39:13 by vshelia           #+#    #+#             */
/*   Updated: 2020/02/25 19:32:42 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

void	ft_error(const char *msg)
{
	if (msg)
	{
		write(2, F_RED, 5);
		write(2, msg, ft_strlen(msg));
		write(2, RESET, 4);
		if (errno)
			write(2, ": ", 2);
		else
			write(2, "\n", 1);
	}
	if (errno)
	{
		perror(NULL);
		exit(errno);
	}
	else
		exit(1);
}
