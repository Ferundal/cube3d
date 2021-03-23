#include "cub3d.h"
#include "cub3d_read_map.h"
#include "flag_utils.h"
#include "cub3d_errors.h"
#include "cub3d_map.h"
#include <stdlib.h>

ERROR_CODE 	map_lc_check(char *str, FLAG_STORE *flags)
{
	while (*str != '\0')
	{
		if ((*str == 'N') || (*str == 'S') || (*str == 'W') || (*str == 'E'))
		{
			if (is_f(flags, FLAG_PLAYER) == 0)
				set_f(flags, FLAG_PLAYER, 1);
			else
				return (ERROR_TWO_PLAYERS_ON_MAP);
		}
		else
			if (!((*str == '1') || (*str == ' ') || (*str == '0') || (*str == '2')))
				return (ERROR_MAP_ERROR);
		++str;
	}
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
	int 		counter;

	status = map_clone(&(par->map_i), &temp_map);
	if (status != 0)
		return (status);
	status = map_check_flow(&temp_map);
	counter = 0;
	while (counter < temp_map.height)
	{
		free(*(temp_map.map + counter));
		++counter;
	}
	free(temp_map.map);
	return (status);
}