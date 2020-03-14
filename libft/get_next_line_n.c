/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 16:25:21 by vshelia           #+#    #+#             */
/*   Updated: 2019/12/30 16:27:42 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int		read_fd(const int fd, char **heap_buffer)
{
	char	read_buffer[BUFF_SIZE + 1];
	char	*temp_buf;
	int		rd;

	ft_bzero((void *)read_buffer, BUFF_SIZE + 1);
	while ((rd = read(fd, read_buffer, BUFF_SIZE)))
	{
		if (rd == -1)
			return (-1);
		if (*heap_buffer)
		{
			temp_buf = *heap_buffer;
			*heap_buffer = ft_strjoin(*heap_buffer, read_buffer);
			ft_strdel(&temp_buf);
		}
		else
			*heap_buffer = ft_strdup(read_buffer);
		if (!heap_buffer)
			return (-1);
		if (ft_strchr(*heap_buffer, '\n'))
			break ;
		ft_bzero((void *)read_buffer, BUFF_SIZE + 1);
	}
	return ((rd > 0 || *heap_buffer) ? 1 : rd);
}

static int		read_buff(int exit_code, char **heap_buffer, char **line)
{
	char	*temp;
	char	*newline_ptr;

	if (*heap_buffer && (newline_ptr = ft_strchr(*heap_buffer, '\n')))
	{
		*line = ft_strsub(*heap_buffer, 0, newline_ptr - *heap_buffer + 1);
		temp = *heap_buffer;
		*heap_buffer = ft_strdup(newline_ptr + 1);
		ft_strdel(&temp);
	}
	else if (*heap_buffer)
	{
		if (**heap_buffer == '\0')
			exit_code = 0;
		else
			*line = ft_strdup(*heap_buffer);
		ft_strdel(heap_buffer);
	}
	return (exit_code);
}

static t_fds	*buf_definer(const int fd, t_fds **fd_buf)
{
	t_fds	*new_buf;
	t_fds	*temp;

	temp = *fd_buf;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	new_buf = ft_memalloc(sizeof(*new_buf));
	if (new_buf)
	{
		new_buf->fd = fd;
		new_buf->next = *fd_buf;
		*fd_buf = new_buf;
	}
	return (new_buf);
}

int				get_next_line_n(const int fd, char **line)
{
	static t_fds	*fd_buf;
	t_fds			*buffer;
	int				exit_code;

	buffer = buf_definer(fd, &fd_buf);
	if (!buffer || !line || fd < 0 || read(fd, buffer->buffer, 0) == -1)
		return (-1);
	exit_code = read_fd(fd, &(buffer->buffer));
	exit_code = read_buff(exit_code, &(buffer->buffer), line);
	return (exit_code);
}
