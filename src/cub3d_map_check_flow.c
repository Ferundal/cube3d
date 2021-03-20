#include "cub3d.h"
#include "cub3d_errors.h"
#include "cub3d_map.h"
#include "cub3d_map.h"

ERROR_CODE	ft_flow_switch_1(t_map_i *map, int x, int y)
{
	ERROR_CODE	status;

	status = 0;
	if (get_map_value(*map, x + 1, y) != '1')
		status = ft_flow(map, x + 1, y);
	if ((status == 0) && (get_map_value(*map, x + 1, y + 1) != '1'))
		status = ft_flow(map, x + 1, y + 1);
	if ((status == 0) && (get_map_value(*map, x, y + 1) != '1'))
		status = ft_flow(map, x, y + 1 );
	if ((status == 0) && (get_map_value(*map, x - 1, y + 1) != '1'))
		status = ft_flow(map, x - 1, y + 1);
	if (status != 0)
		return (ERROR_MAP_NOT_CLOSED);
	return (0);
}

ERROR_CODE	ft_flow_switch_2(t_map_i *map, int x, int y)
{
	ERROR_CODE	status;

	status = 0;
	if (get_map_value(*map, x - 1, y) != '1')
		status += ft_flow(map, x - 1, y);
	if ((status == 0) && (get_map_value(*map, x - 1, y - 1) != '1'))
		status += ft_flow(map, x - 1, y - 1);
	if ((status == 0) && (get_map_value(*map, x, y - 1) != '1'))
		status += ft_flow(map, x, y - 1 );
	if ((status == 0) && (get_map_value(*map, x + 1, y - 1) != '1'))
		status += ft_flow(map, x + 1, y - 1);
	if (status != 0)
		return (ERROR_MAP_NOT_CLOSED);
	return (0);
}

ERROR_CODE	ft_flow(t_map_i *map, int x, int y)
{
	ERROR_CODE	status;

	if ((get_map_value(*map, x, y)) == ' ')
		return (ERROR_MAP_NOT_CLOSED);
	if ((x == 0) || (x == map->width - 1) || (y == 0) || (y == map->height - 1))
		return (ERROR_MAP_NOT_CLOSED);
	*(*(map->map + y) + x) = '1';
	status = 0;
	if ((status = ft_flow_switch_1(map, x, y)) == 0)
		status = ft_flow_switch_2(map, x, y);
	if (status != 0)
		return (ERROR_MAP_NOT_CLOSED);
	return (0);
}

ERROR_CODE	map_check_flow(t_map_i *map)
{
	ERROR_CODE	status;
	int 		x;
	int 		y;

	status = find_map_value("NSWE", *map, &x, &y);
	if (status != 0)
		return (ERROR_NO_PLAYER_ON_MAP);
	status = ft_flow(map, x, y);
	return (status);
}

