#include "cub3d.h"
#include "cub3d_errors.h"
#include "cub3d_map.h"

ERROR_CODE	ft_flow(t_map_i *map, int x, int y)
{
	ERROR_CODE	status;
	char 		value;

	status = 0;
	*(*(map->map + y) + x) = '1';
	if ((x == 0) || (x == map->width - 1) || (y == 0) || (y == map->height - 1))
		return (ERROR_MAP_NOT_CLOSED);
	if ((value = get_map_value(*map, x + 1, y)) == ' ')
		return (ERROR_MAP_NOT_CLOSED);
	else
	{
		if (value != '1')
			status = ft_flow(map, x + 1, y);
	}
	if ((value = get_map_value(*map, x + 1, y)) == ' ')
		return (ERROR_MAP_NOT_CLOSED);
	else
	{
		if (value != '1')
			status = ft_flow(map, x + 1, y);
	}
	if ((value = get_map_value(*map, x + 1, y)) == ' ')
		return (ERROR_MAP_NOT_CLOSED);
	else
	{
		if (value != '1')
			status = ft_flow(map, x + 1, y);
	}
}


ERROR_CODE	map_check_flow(t_map_i *map)
{
	ERROR_CODE	status;
	int 		x;
	int 		y;

	status = find_map_value("NSWE", *map, &x, &y);
	if (status != 0)
		return (ERROR_NO_PLAYER_ON_MAP);


}

