#include "cub3d.h"
#include "cub3d_read_map.h"
#include "flag_utils.h"
#include "cub3d_errors.h"
#include "cub3d_map.h"
#include <stdlib.h>

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
		++str;
	}
	if (line_status < 0)
		return (ERROR_MAP_ERROR);
	return (0);
}

ERROR_CODE	map_clone(t_map_i *src, t_map_i *dst)
{
	int 		counter;

	dst->height = src->height;
	dst->width = src->width;
	if((dst->map = (char**)malloc(sizeof(char*) * src->height)) == NULL)
		return (ERROR_CAN_NOT_ALLOCATE_MEMORY);
	counter = 0;
	while (counter < dst->height)
	{
		*(dst->map + counter) = ft_strdup(*(src->map + counter));
		if (*(dst->map + counter) == NULL)
		{
			while (counter > 0)
			{
				free(*(dst->map + counter - 1));
				--counter;
			}
			free(dst->map);
			return (ERROR_CAN_NOT_ALLOCATE_MEMORY);
		}
		++counter;
	}
	return (0);
}



ERROR_CODE 	map_check(t_par *par)
{
	ERROR_CODE	status;
	t_map_i 	temp_map;

	status = map_clone(&(par->map_i), &temp_map);
	if (status != 0)
		return (status);
	status = map_check_flow(&temp_map);
	while (temp_map.height > 0)
	{
		free(*(temp_map.map + temp_map.height - 1));
		temp_map.height -= 1;
	}
	free(temp_map.map);
	return (status);
}