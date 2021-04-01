/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:00:56 by cjettie           #+#    #+#             */
/*   Updated: 2021/04/01 15:54:25 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*strrebuffl(char *str, size_t *str_l, \
		const char *buff, size_t len)
{
	char			*result;
	size_t			counter;

	result = (char *)malloc(sizeof(char) * (*str_l + len + 1));
	if (result != NULL)
	{
		counter = 0;
		while (counter < *str_l)
		{
			*(result + counter) = *(str + counter);
			counter++;
		}
		counter = 0;
		while (counter < len)
		{
			*(result + *str_l + counter) = *(buff + counter);
			counter++;
		}
		*(result + *str_l + len) = '\0';
		*str_l += len;
	}
	if (str != NULL)
		free(str);
	return (result);
}

static int	add_line_part(t_fd_i *fd_i_p, size_t *str_l, \
		char **line, char *is_eol_p)
{
	int				i;

	i = 0;
	while (fd_i_p->pos < fd_i_p->size)
	{
		if (*(fd_i_p->buff_p + fd_i_p->pos) == '\n')
		{
			*is_eol_p = 1;
			break ;
		}
		++fd_i_p->pos;
		++i;
	}
	*line = strrebuffl(*line, str_l, fd_i_p->buff_p + fd_i_p->pos - i, i);
	if (*line == NULL)
		return (1);
	return (0);
}

static int	read_line(t_fd_i *fd_i_p, char **line, char *is_eol)
{
	size_t			str_l;

	str_l = 0;
	*is_eol = 0;
	while (*is_eol == 0)
	{
		if (add_line_part(fd_i_p, &str_l, line, is_eol) != 0)
			return (1);
		if (*is_eol == 0)
		{
			if (fd_i_p->size != BUFFER_SIZE)
				*is_eol = 2;
			else
			{
				fd_i_p->size = read(fd_i_p->fd, fd_i_p->buff_p, BUFFER_SIZE);
				fd_i_p->pos = 0;
			}
		}
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_fd_i	**fd_i_pp = NULL;
	t_fd_i			*fd_i_p;
	char			is_eol;

	if ((fd < 0) || (BUFFER_SIZE < 1))
		return (-1);
	if (get_fd_info(fd, &fd_i_pp, &fd_i_p) != 0)
		return (-1);
	if (*line != NULL)
		*line = NULL;
	if (read_line(fd_i_p, line, &is_eol) != 0)
		return (-1);
	if ((is_eol == 2) || (fd_i_p->pos == fd_i_p->size))
	{
		fd_i_p->size = read(fd_i_p->fd, fd_i_p->buff_p, BUFFER_SIZE);
		if ((is_eol == 2) && (fd_i_p->size == 0))
		{
			del_fd_info(fd_i_p->fd, &fd_i_pp);
			return (0);
		}
		fd_i_p->pos = 0;
	}
	else
		fd_i_p->pos += 1;
	return (1);
}
