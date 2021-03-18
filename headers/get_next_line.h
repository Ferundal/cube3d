/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:04:54 by cjettie           #+#    #+#             */
/*   Updated: 2020/12/06 16:11:20 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <sys/types.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_fd_i
{
	int			fd;
	char		*buff_p;
	ssize_t		size;
	ssize_t		pos;
}				t_fd_i;

int				get_next_line(int fd, char **line);
int				get_fd_info(int fd, t_fd_i ***fd_i_ppp, t_fd_i **fd_i_pp);
int				del_fd_info(int fd, t_fd_i ***fd_i_ppp);
#endif
