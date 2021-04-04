#include <math.h>
#include "cub3d.h"
#include "cub3d_draw.h"

void	rotate_right(t_draw_data *data)
{
	double	temp;

	temp = data->dir_x;
	data->dir_x = data->dir_x * cos(data->r_speed) - \
		data->dir_y * sin(data->r_speed);
	data->dir_y = temp * sin(data->r_speed) + \
		data->dir_y * cos(data->r_speed);
	temp = data->plane_x;
	data->plane_x = data->plane_x * cos(data->r_speed) - \
		data->plane_y * sin(data->r_speed);
	data->plane_y = temp * sin(data->r_speed) + \
		data->plane_y * cos(data->r_speed);
}

void	rotate_left(t_draw_data *data)
{
	double	temp;

	temp = data->dir_x;
	data->dir_x = data->dir_x * cos(-data->r_speed) - \
		data->dir_y * sin(-data->r_speed);
	data->dir_y = temp * sin(-data->r_speed) + \
		data->dir_y * cos(-data->r_speed);
	temp = data->plane_x;
	data->plane_x = data->plane_x * cos(-data->r_speed) - \
		data->plane_y * sin(-data->r_speed);
	data->plane_y = temp * sin(-data->r_speed) + \
		data->plane_y * cos(-data->r_speed);
}
