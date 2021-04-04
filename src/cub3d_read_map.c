#include "cub3d_parcer.h"
#include "get_next_line.h"
#include "cub3d_read_map.h"

static void	skip_empty(int fd, char **str, int *r_st)
{
	while ((*r_st == 1) && (**str == '\0'))
	{
		free(*str);
		*r_st = get_next_line(fd, str);
	}
}

static int	add_map_line(char *str, t_par *par)
{
	char		**temp_map;
	int			temp;

	temp_map = (char **)malloc(sizeof(char *) * (par->map_i.h + 1));
	if (temp_map == NULL)
		return (ERROR_CAN_NOT_ALLOCATE_MEMORY);
	temp = 0;
	while (temp < par->map_i.h)
	{
		*(temp_map + temp) = *(par->map_i.map + temp);
		++temp;
	}
	*(temp_map + temp) = str;
	if (par->map_i.map != NULL)
		free(par->map_i.map);
	par->map_i.map = temp_map;
	par->map_i.h += 1;
	temp = ft_strlen(str);
	if (temp > par->map_i.w)
		par->map_i.w = temp;
	return (0);
}

static ERROR_CODE	read_lines(int fd, t_par *par, int *flags)
{
	int			r_st;
	char		*str;
	ERROR_CODE	l_st;

	r_st = get_next_line(fd, &str);
	skip_empty(fd, &str, &r_st);
	l_st = map_lc_check(str, flags);
	while ((r_st == 1) && (l_st == 0))
	{
		add_map_line(str, par);
		r_st = get_next_line(fd, &str);
		l_st = map_lc_check(str, flags);
	}
	if ((r_st == 0) && (l_st == 0))
	{
		add_map_line(str, par);
		return (0);
	}
	if (str != NULL)
		free(str);
	if (r_st < 0)
		return (ERROR_CANT_GET_MAP_LINE);
	return (l_st);
}

ERROR_CODE	read_map(int fd, t_par *par)
{
	ERROR_CODE	status;
	int			p_flag;

	p_flag = 0;
	status = read_lines(fd, par, &p_flag);
	if (status > 0)
		return (status);
	if (p_flag == 0)
		return (ERROR_NO_PLAYER_ON_MAP);
	return (map_check(par));
}
