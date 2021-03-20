#include "cub3d.h"
#include "cub3d_read_map.h"
#include "flag_utils.h"
#include "cub3d_errors.h"
#include "cub3d_map.h"

ERROR_CODE 	map_line_c_check(char *str, FLAG_STORE *flags)
{
	ERROR_CODE	line_status;

	line_status = -1;
	while (*str != '\0')
	{
		if ((*str == 'N') || (*str == 'S') || (*str == 'W') || (*str == 'E'))
		{
			if (is_f(flags, FLAG_PLAYER) == 0)
			{
				set_f(flags, FLAG_PLAYER, 1);
				line_status = 0;
			}
			else
				return (ERROR_TWO_PLAYERS_ON_MAP);
		}
		if (*str == '1')
			line_status = 0;
	}
	if (line_status < 0)
		return (ERROR_MAP_ERROR);
	return (0);
}

ERROR_CODE	map_check_pair(char prev, char next)
{
	if ((next == ' ') && (prev != '1') && (prev != ' '))
		return (ERROR_MAP_NOT_CLOSED);
	if ((next != '1') && (next != ' ') && (prev == ' '))
		return (ERROR_MAP_NOT_CLOSED);
	return (0);
}

ERROR_CODE 	map_line_check(char *str)
{
	char		prev;
	ERROR_CODE	status;

	prev = ' ';
	while (*str != '\0')
	{
		if ((status = map_check_pair(prev, *str)) != 0)
			return (status);
		prev = *str;
		++str;
	}
	status = map_check_pair(prev, ' ');
	return (status);
}

ERROR_CODE 	map_collum_check(t_par *par, int x)
{
	char		prev;
	char 		next;
	ERROR_CODE	status;
	int 		y;

	prev = ' ';
	y = 0;
	while (y < par->map_i.height)
	{
		next = get_map_value(par->map_i, x, y);
		status = map_check_pair(prev, next);
		if (status != 0)
			return (status);
		prev = next;
		++y;
	}
	status = map_check_pair(prev, ' ');
	return (status);
}

ERROR_CODE 	map_check(t_par *par)
{
	int 		x;
	int 		y;
	ERROR_CODE	status;

	x = 0;
	y = 0;
	while (y < par->map_i.height)
	{
		if ((status = map_line_check(*(par->map_i.map + y))) != 0)
			return (status);
		++y;
	}
	while (x < par->map_i.width)
	{
		if ((status = map_collum_check(par, x)) != 0)
			return (status);
		++x;
	}
	return (0);
}