/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:21:00 by cjettie           #+#    #+#             */
/*   Updated: 2020/12/08 15:20:11 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "get_next_line.h"

static int	new_fd_info(int fd, t_fd_i **fd_i_pp)
{
	*fd_i_pp = (t_fd_i*)malloc(sizeof(t_fd_i));
	if (*fd_i_pp == NULL)
		return (1);
	(*fd_i_pp)->buff_p = (char*)malloc(sizeof(char) * BUFFER_SIZE);
	if ((*fd_i_pp)->buff_p == NULL)
	{
		free(*fd_i_pp);
		*fd_i_pp = NULL;
		return (2);
	}
	(*fd_i_pp)->size = read(fd, (*fd_i_pp)->buff_p, BUFFER_SIZE);
	if ((*fd_i_pp)->size < 0)
	{
		free((*fd_i_pp)->buff_p);
		free(*fd_i_pp);
		*fd_i_pp = NULL;
		return (3);
	}
	(*fd_i_pp)->fd = fd;
	(*fd_i_pp)->pos = 0;
	return (0);
}

int			del_fd_info(int fd, t_fd_i ***fd_i_ppp)
{
	t_fd_i	**temp_fd_i_pp;
	char	fd_found_flag;

	temp_fd_i_pp = *fd_i_ppp;
	fd_found_flag = 0;
	while (*temp_fd_i_pp != NULL)
	{
		if ((*temp_fd_i_pp)->fd == fd)
		{
			fd_found_flag = 1;
			free((*temp_fd_i_pp)->buff_p);
			free(*temp_fd_i_pp);
		}
		if (fd_found_flag == 1)
			*temp_fd_i_pp = *(temp_fd_i_pp + 1);
		++temp_fd_i_pp;
	}
	if (fd_found_flag == 0)
		return (1);
	if (**fd_i_ppp == NULL)
	{
		free(*fd_i_ppp);
		*fd_i_ppp = NULL;
	}
	return (0);
}

static void	cpy_fd_info(t_fd_i ***fd_i_ppp, t_fd_i ***new_fd_i_ppp)
{
	t_fd_i **temp_fd_i_pp;

	temp_fd_i_pp = *fd_i_ppp;
	while (*temp_fd_i_pp != NULL)
	{
		**new_fd_i_ppp = *temp_fd_i_pp;
		*new_fd_i_ppp += 1;
		++temp_fd_i_pp;
	}
}

static int	add_fd_info(int fd, t_fd_i ***fd_i_ppp, size_t new_size)
{
	t_fd_i **new_fd_i_pp;

	new_fd_i_pp = (t_fd_i **)malloc(sizeof(t_fd_i *) * (new_size + 1));
	if (new_fd_i_pp == NULL)
		return (1);
	if (new_fd_info(fd, new_fd_i_pp) != 0)
	{
		free(new_fd_i_pp);
		return (2);
	}
	++new_fd_i_pp;
	if (*fd_i_ppp != NULL)
	{
		cpy_fd_info(fd_i_ppp, &new_fd_i_pp);
		free(*fd_i_ppp);
	}
	*(new_fd_i_pp) = NULL;
	*fd_i_ppp = new_fd_i_pp - new_size;
	return (0);
}

int			get_fd_info(int fd, t_fd_i ***fd_i_ppp, t_fd_i **fd_i_pp)
{
	t_fd_i	**t_fd_i_pp;

	if (*fd_i_ppp == NULL)
	{
		if (add_fd_info(fd, fd_i_ppp, 1) != 0)
			return (1);
		*fd_i_pp = **fd_i_ppp;
		return (0);
	}
	t_fd_i_pp = *fd_i_ppp;
	while (*t_fd_i_pp != NULL)
	{
		if ((*t_fd_i_pp)->fd == fd)
		{
			*fd_i_pp = *t_fd_i_pp;
			return (0);
		}
		t_fd_i_pp++;
	}
	if (add_fd_info(fd, fd_i_ppp, t_fd_i_pp - *fd_i_ppp + 1) != 0)
		return (1);
	*fd_i_pp = **fd_i_ppp;
	return (0);
}
