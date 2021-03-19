#include "cub3d.h"
#include "cub3d_read_map.h"
#include "flag_utils.h"
#include "cub3d_errors.h"

ERROR_CODE 	map_line_check(char *str, FLAG_STORE *flags)
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

char		get_map_value(t_map_i map_i, int x, int y)
{
	char 		*temp_str;

	if ((x > map_i.width) || (y > map_i.height))
		return (-1);
	temp_str = *(map_i.map + y);
	while (x > 0)
	{
		if ((*temp_str) == '\0')
			return (' ');
		--x;
		++temp_str;
	}
	return (*temp_str);
}

int 		find_map_value(char *value, t_map_i map_i, int *x, int *y)
{
	char 	*temp;

	*x = 0;
	*y = 0;
	while (*x < map_i.width)
	{
		while (*y < map_i.height)
		{
			temp = value;
			while (*temp != '\0')
			{
				if (*(*(map_i.map + *x) + *y) == *temp)
					return (0);
				++temp;
			}
			*y += 1;
		}
		*x += 1;
	}
	return (1);
}



ERROR_CODE 	map_check(t_par *par)
{
	int 	x;
	int 	y;

	if (find_map_value("NSWE", par->map_i, &x, &y) != 0)
		return (ERROR_NO_PLAYER_ON_MAP);

}