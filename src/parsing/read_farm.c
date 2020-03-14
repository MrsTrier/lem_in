/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_farm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:34:26 by vshelia           #+#    #+#             */
/*   Updated: 2020/03/09 14:28:21 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <unistd.h>
#include <sys/types.h>

char		*read_fd(int fd)
{
	char	*string;
	char	*temp;
	char	read_buf[BUF64KB + 1];
	ssize_t	rd;

	string = NULL;
	while ((rd = read(fd, read_buf, BUF64KB)))
	{
		if (rd == -1)
			ft_error("Error in reading a file descriptor (read_fd)");
		read_buf[rd] = '\0';
		if (string)
		{
			temp = string;
			string = ft_strjoin(string, read_buf);
			free(temp);
		}
		else
			string = ft_strdup(read_buf);
		if (!string)
			ft_error("Error in memory allocation (read_fd)");
	}
	return (string);
}

void		parse_links_names(char *parse_str, char *str_end, char **names)
{
	char	*dash;
	char	*str;

	if (!str_end)
		error(ERR_LINK_NO_LF, parse_str);
	dash = strchr_until(parse_str, '-', str_end);
	if (dash == parse_str)
		error(ERR_LINK_NO_F_ROOM, parse_str);
	if (str_end - dash == 1)
		error(ERR_LINK_NO_S_ROOM, parse_str);
	str = parse_str;
	while (str < dash)
		if (*str == ' ' || !ft_isprint(*str++))
			error(ERR_LINK_F_N_P, parse_str);
	str++;
	while (str < str_end)
		if (*str == '-' || *str == ' ' || !ft_isprint(*str++))
			error(ERR_LINK_S_N_P, parse_str);
	names[0] = ft_strsub(parse_str, 0, dash - parse_str);
	names[1] = ft_strsub(dash, 1, str_end - dash - 1);
	if (!names[0] || !names[1])
		ft_error("Error in memory allocation (parse_links_names)");
}

static void	print_error_line_number(const char *str)
{
	unsigned	line_nb;
	char		*str_line_nb;

	write(2, "\e[31mERROR: \e[0m", 16);
	if (str)
	{
		line_nb = 1;
		while (str > g_map && *(str - 1) != '\n')
			str--;
		while (g_map < str)
			if (*g_map++ == '\n')
				line_nb++;
		if (!(str_line_nb = ft_ulltoa_base(line_nb, 10)))
			ft_error("Error in memory allocation (print_error_line_number)");
		write(2, "line ", 5);
		write(2, str_line_nb, ft_strlen(str_line_nb));
		write(2, ": ", 2);
		free(str_line_nb);
	}
}

void		error(const char *msg, const char *str)
{
	if (msg)
	{
		print_error_line_number(str);
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	exit(1);
}

char		*strchr_until(const char *str, int c, const char *end)
{
	char	*ptr;

	ptr = ft_strchr(str, c);
	if (!ptr || ptr >= end)
		error(ERR_NO_EXPECTED_SYMB, str);
	return (ptr);
}
