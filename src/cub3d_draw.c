#include "cub3d.h"
#include "cub3d_draw.h"
#include "cub3d_errors.h"
#include "cub3d_map.h"

void	choose_dir(t_draw_data *data, char start)
{
	if ((start == 'N') || (start == 'S'))
	{
		data->dirX = 0;
		data->dirY = -1;
		data->plane_x = 0.66;
		data->planeY = 0;
	}
	if ((start == 'W') || (start == 'E'))
	{
		data->dirX = -1;
		data->dirY = 0;
		data->plane_x = 0;
		data->planeY = -0.66;
	}
	if ((start == 'S') || (start == 'E'))
	{
		data->dirX = -data->dirX ;
		data->dirY = -data->dirY;
		data->plane_x = -data->plane_x;
		data->planeY = -data->planeY;
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
	if ((is_error = find_all("2", data->par.map_i, &data->spr_arr)) != 0)
		return (is_error);
	find_map_value("NSWE", data->par.map_i, &x, &y);
	start = get_map_value(data->par.map_i, x, y);
	choose_dir(data, start);
	data->posX = (double) x + 0.5;
	data->posY = (double) y + 0.5;
	data->moveSpeed = 0.05;
	data->rotSpeed = 0.05;
	data->keys.r_right = 0;
	data->keys.r_left = 0;
	data->keys.m_right = 0;
	data->keys.m_left = 0;
	data->keys.m_forw= 0;
	data->keys.m_back = 0;
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
	double		z_buffer[par->rez.width];

	data.mlx = *mlx;
	data.par = *par;
	data.mlx.win = mlx_new_window(data.mlx.mlx, data.par.rez.width, data.par.rez.height, "cub3d");
	data.img.img = mlx_new_image(data.mlx.mlx, data.par.rez.width, data.par.rez.height);
	data.img.buff = (char*)mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel,
									&data.img.line_length, &data.img.endian);
	if((is_error = init_data(&data)) != 0)
		return (is_error);
	data.z_buff = &z_buffer[0];
	mlx_hook(data.mlx.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx.win, 3, 1L << 1, key_unpress, &data);
	mlx_hook(data.mlx.win, 17, 0, exit_pressed, &data);
	mlx_loop_hook(data.mlx.mlx, move_calc, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}

