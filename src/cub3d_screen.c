#include "../headers/cub3d.h"

int		screen(t_par *par, t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->mlx, par->rez.width, par->rez.height, "Hello world!");
	return (par->rez.width);
}
