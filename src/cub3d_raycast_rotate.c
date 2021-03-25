#include <math.h>
#include "cub3d.h"
#include "cub3d_map.h"
#include "cub3d_draw.h"

void		rotate_right(t_draw_data *data)
{
	double	temp;

	temp = data->dirX;
	data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY * sin(data->rotSpeed);
	data->dirY = temp * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
	temp = data->planeX;
	data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
	data->planeY = temp * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);
}

void		rotate_left(t_draw_data *data)
{
	double	temp;

	temp = data->dirX;
	data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
	data->dirY = temp * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
	temp = data->planeX;
	data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
	data->planeY = temp * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
}