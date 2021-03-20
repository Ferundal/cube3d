#include "cub3d_parcer.h"
#include "get_next_line.h"
#include "cub3d_read_map.h"

int 	add_map_line(char *str, t_par *par)
{
	char		**temp_map;
	int 		temp;

	temp_map = (char**)malloc(sizeof(char*) * (par->map_i.height + 1));
	if (temp_map == NULL)
		return (ERROR_CAN_NOT_ALLOCATE_MEMORY);
	temp = 0;
	while (temp < par->map_i.height)
	{
		*(temp_map + temp) = *(par->map_i.map + temp);
		++temp;
	}
	*(temp_map + temp) = str;
	if (par->map_i.map != NULL)
		free(par->map_i.map);
	par->map_i.map = temp_map;
	par->map_i.height += 1;
	temp = ft_strlen(str);
	if (temp > par->map_i.width)
		par->map_i.width = temp;
	return (0);
}


ERROR_CODE	read_lines(int fd, t_par *par, FLAG_STORE *flags)
{
	int			r_st;
	char 		*curr_line;
	ERROR_CODE	l_st;

	r_st = get_next_line(fd, &curr_line);
	while ((r_st == 1) && (*curr_line == '\0'))
	{
		free(curr_line);
		r_st = get_next_line(fd, &curr_line);
	}
	while ((r_st == 1) && ((l_st = map_line_c_check(curr_line, flags)) == 0))
	{
		add_map_line(curr_line, par);
		r_st = get_next_line(fd, &curr_line);
	}
	if ((r_st == 0) && ((l_st = map_line_c_check(curr_line, flags)) == 0))
	{
		add_map_line(curr_line, par);
		return (0);
	}
	if (curr_line != NULL)
		free(curr_line);
	return (r_st < 0 ? ERROR_CANT_GET_MAP_LINE : l_st);
}

ERROR_CODE	read_map(int fd, t_par *par)
{
	ERROR_CODE	status;
	FLAG_STORE	flags;

	flags = 0;
	status = read_lines(fd, par, &flags);
	if (status > 0)
		return (status);
	if (is_f(&flags, FLAG_PLAYER) == 0)
		return (ERROR_NO_PLAYER_ON_MAP);
	return (map_check(par));
}

