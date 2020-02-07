/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:01:08 by mcanhand          #+#    #+#             */
/*   Updated: 2019/05/10 19:14:56 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 600
# define MAX_FD 1025
# define RET_VALUE(ret) ret > 0 ? 1 : ret
# include "libft.h"

int		get_next_line(const int fd, char **line);

#endif
