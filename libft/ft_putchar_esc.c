/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_esc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:10:30 by vshelia           #+#    #+#             */
/*   Updated: 2019/09/20 22:59:15 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_esc(const char *esc, char ch)
{
	ft_putstr(esc);
	ft_putchar(ch);
	ft_putstr(RESET);
}
