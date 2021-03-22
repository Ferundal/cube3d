#include "cub3d.h"
#include "cub3d_draw.h"
#include "cub3d_errors.h"
#include "cub3d_map.h"


void	init_player(t_player *data, t_par *par)
{
	int		x;
	int		y;
	char	start;

	find_map_value("NSWE", par->map_i, &x, &y);
	start = get_map_value(par->map_i, x, y);
	data->posX = (double) x;
	data->posY = (double) y;
	data->dirX = -1;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = 0.66;
	data->moveSpeed = 0.1; //the constant value is in squares/second
	data->rotSpeed = 0.3;
}

ERROR_CODE	draw_frame(t_par *par, t_img *img, t_mlx *mlx, t_player *player)
{
	draw_background(img, par);
	raycast(par, img, mlx, &player);
	mlx_put_image_to_window(mlx, mlx->win, img->img, 0, 0);
	return (0);
}

ERROR_CODE	draw(t_par *par, t_mlx *mlx)
{
	t_img 		img;
	t_player	    data;

	mlx->win = mlx_new_window(mlx->mlx, par->rez.width, par->rez.height, "cub3d");
	img.img = mlx_new_image(mlx->mlx, par->rez.width, par->rez.height);
	img.buff = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	init_player(&data, par);
	draw_frame(par, &img, mlx, &data);
	mlx_loop(mlx->mlx);
	return (0);
}

