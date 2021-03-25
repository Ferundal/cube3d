#include "cub3d.h"
#include "cub3d_draw.h"
#include "cub3d_errors.h"
#include "cub3d_map.h"

void	choose_dir(t_draw_data *data, char start)
{
	if (start == 'N')
	{
		data->dirX = 0;
		data->dirY = -1;
		data->planeX = 0.66;
		data->planeY = 0;
	}
	if (start == 'S')
	{
		data->dirX = 0;
		data->dirY = 1;
		data->planeX = -0.66;
		data->planeY = 0;
	}
	if (start == 'W')
	{
		data->dirX = -1;
		data->dirY = 0;
		data->planeX = 0;
		data->planeY = -0.66;
	}
	if (start == 'E')
	{
		data->dirX = 1;
		data->dirY = 0;
		data->planeX = 0;
		data->planeY = 0.66;
	}
}

void	init_player(t_draw_data *data)
{
	int		x;
	int		y;
	char	start;

	find_map_value("NSWE", data->par.map_i, &x, &y);
	start = get_map_value(data->par.map_i, x, y);
	choose_dir(data, start);
	data->posX = (double) x + 0.5;
	data->posY = (double) y + 0.5;
	data->moveSpeed = 0.05; //the constant value is in squares/second
	data->rotSpeed = 0.05;
}

ERROR_CODE	draw_frame(t_draw_data *data)
{
	raycast(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->img.img, 0, 0);
	mlx_do_sync(data->mlx.mlx);
	return (0);
}

ERROR_CODE	draw(t_par *par, t_mlx *mlx)
{
	t_draw_data	data;

	data.mlx = *mlx;
	data.par = *par;
	data.mlx.win = mlx_new_window(data.mlx.mlx, data.par.rez.width, data.par.rez.height, "cub3d");
	data.img.img = mlx_new_image(data.mlx.mlx, data.par.rez.width, data.par.rez.height);
	data.img.buff = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel,
									&data.img.line_length, &data.img.endian);
	init_player(&data);
	mlx_hook(data.mlx.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx.win, 3, 1L << 1, key_unpress, &data);
	mlx_hook(data.mlx.win, 17, 0, exit_pressed, &data);
	mlx_loop_hook(data.mlx.mlx, move_calc, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}

