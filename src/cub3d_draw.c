#include "cub3d.h"

int		draw(t_par *par, t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->mlx, par->rez.width, par->rez.height, "cub3d");
	mlx_loop(mlx->mlx);
	return (par->rez.height);
}

