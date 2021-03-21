#include "cub3d.h"
#include "cub3d_draw.h"
#include "cub3d_errors.h"
#include "cub3d_map.h"


void	init_player(t_player *player, t_par *par) {
	int x;
	int y;

	find_map_value("NSWE", par->map_i, &x, &y);
	player->posX = (double) x;
	player->posY = (double) y;
	player->dirX = -1;
	player->dirY = 0;
}

void	ft_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char    *dst;

	dst = data->buff + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void 	draw_background(t_img *data, t_par *par)
{
	char 	*dst;
	int 	half;
	int 	counter;
	int 	x_step;

	dst = data->buff;
	half = par->rez.height / 2;
	x_step = data->bits_per_pixel / 8;
	counter = half * par->rez.width;
	while (counter > 0)
	{
		*(unsigned int*)dst = par->ceil;
		--counter;
		dst += x_step;
	}
	counter = (par->rez.height - half) * par->rez.width;
	while (counter > 0)
	{
		*(unsigned int*)dst = par->floor;
		--counter;
		dst += x_step;
	}
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
	t_player	player;

	mlx->win = mlx_new_window(mlx->mlx, par->rez.width, par->rez.height, "cub3d");
	img.img = mlx_new_image(mlx->mlx, par->rez.width, par->rez.height);
	img.buff = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	init_player(&player, par);
	draw_frame(par, &img, mlx, &player);
	mlx_loop(mlx->mlx);
	return (0);
}

