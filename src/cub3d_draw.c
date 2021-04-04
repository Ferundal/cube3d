#include "cub3d.h"
#include "cub3d_draw.h"
#include "cub3d_errors.h"
#include "cub3d_map.h"
#include <stdlib.h>

static void	choose_dir(t_draw_data *data, char start)
{
	if ((start == 'N') || (start == 'S'))
	{
		data->dir_x = 0;
		data->dir_y = -1;
		data->plane_x = 0.66;
		data->plane_y = 0;
	}
	if ((start == 'W') || (start == 'E'))
	{
		data->dir_x = -1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
	if ((start == 'S') || (start == 'E'))
	{
		data->dir_x = -data->dir_x ;
		data->dir_y = -data->dir_y;
		data->plane_x = -data->plane_x;
		data->plane_y = -data->plane_y;
	}
}

ERROR_CODE	init_data(t_draw_data *data)
{
	ERROR_CODE	is_error;
	int			x;
	int			y;
	char		start;

	data->spr_arr.size = 0;
	data->spr_arr.arr = NULL;
	is_error = find_all("2", data->par.map_i, &data->spr_arr);
	if (is_error != 0)
		return (is_error);
	find_map_value("NSWE", data->par.map_i, &x, &y);
	start = get_map_value(data->par.map_i, x, y);
	choose_dir(data, start);
	data->pos_x = (double) x + 0.5;
	data->pos_y = (double) y + 0.5;
	data->m_speed = 0.05;
	data->r_speed = 0.05;
	data->keys.r_right = 0;
	data->keys.r_left = 0;
	data->keys.m_right = 0;
	data->keys.m_left = 0;
	data->keys.m_forw = 0;
	data->keys.m_back = 0;
	data->z_buff = NULL;
	return (0);
}

ERROR_CODE	draw_frame(t_draw_data *data)
{
	raycast(data);
	draw_sprites(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->img.img, 0, 0);
	mlx_do_sync(data->mlx.mlx);
	return (0);
}

ERROR_CODE	draw(t_par *par, t_mlx *mlx)
{
	ERROR_CODE	is_error;
	t_draw_data	data;

	data.mlx = *mlx;
	data.par = *par;
	is_error = init_data(&data);
	if (is_error != 0)
		return (is_error);
	data.mlx.win = \
		mlx_new_window(data.mlx.mlx, data.par.rez.w, data.par.rez.h, "cub3d");
	data.img.img = mlx_new_image(data.mlx.mlx, data.par.rez.w, data.par.rez.h);
	if (data.img.img == NULL)
		return (ERROR_CAN_NOT_ALLOCATE_MEMORY);
	data.img.buff = (char *)mlx_get_data_addr(data.img.img, \
		&data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	data.z_buff = malloc(sizeof(double) * par->rez.w);
	if (data.z_buff == NULL)
		cub3d_exit(&data, ERROR_CAN_NOT_ALLOCATE_MEMORY);
	mlx_hook(data.mlx.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx.win, 3, 1L << 1, key_unpress, &data);
	mlx_hook(data.mlx.win, 17, 0, exit_pressed, &data);
	mlx_loop_hook(data.mlx.mlx, move_calc, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
