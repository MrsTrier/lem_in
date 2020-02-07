/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:55:03 by galiza            #+#    #+#             */
/*   Updated: 2019/05/21 14:30:43 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		ft_verify_line(char **buffer, char **res)
{
	int		i;
	char	*tmp;
	char	*pr;

	i = 0;
	tmp = *buffer;
	while (tmp[i] != '\n')
		if (!tmp[i++])
			return (0);
	pr = &tmp[i];
	*pr = '\0';
	*res = ft_strsub(*buffer, 0, i);
	tmp = ft_strdup(pr + 1);
	ft_strdel(&*buffer);
	*buffer = tmp;
	return (1);
}

static int		ft_read_file(int fd, char *tmp, char **buffer, char **line)
{
	int		ret;
	char	*cp;

	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		if (*buffer)
		{
			cp = *buffer;
			*buffer = ft_strjoin(cp, tmp);
			free(cp);
		}
		else
			*buffer = ft_strdup(tmp);
		if (ft_verify_line(buffer, line))
			break ;
	}
	return (RET_VALUE(ret));
}

int				support(char *tmp, char **str, const int fd, char **line)
{
	int			i;
	int			ret;

	i = 0;
	while (i < BUFF_SIZE)
		tmp[i++] = '\0';
	ret = ft_read_file(fd, tmp, &str[fd], line);
	free(tmp);
	if (ret != 0 || str[fd] == NULL || str[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = str[fd];
	str[fd] = NULL;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str[MAX_FD];
	char		*tmp;

	tmp = 0;
	if (!line || fd < 0 || fd > MAX_FD || \
		!(tmp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
	{
		free(tmp);
		return (-1);
	}
	if (str[fd])
	{
		if (ft_verify_line(&str[fd], line))
		{
			free(tmp);
			return (1);
		}
	}
	return (support(tmp, &str[fd], fd, line));
}
