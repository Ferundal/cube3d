#include "cub3d.h"
#include "cub3d_draw.h"
#include <stdlib.h>


ERROR_CODE	cub3d_exit(t_draw_data *data)
{
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	exit (0);
}

ERROR_CODE	arg_check(int argc, char **argv)
{
	int 	len;
	int 	f_len;

	if ((argc < 2) || (argc > 3))
		return (ERROR_WRONG_ARG_AMT);
	if ((len = ft_strlen(*(argv + 1))) < 5)
		return (ERROR_WRONG_FIRST_ARG);
	f_len = ft_strlen(FILE_F);
	if (ft_strncmp(*(argv + 1) + len - f_len, FILE_F, f_len) != 0)
		return (ERROR_WRONG_FIRST_ARG);
	if (argc == 3)
	{
		len = ft_strlen(*(argv + 2));
		if ((ft_strncmp(*(argv + 2), SCREEN_FLAG, len) != 0) ||
			(*(*(argv + 2) + len) != '\0'))
			return (ERROR_WRONG_SECOND_ARG);
	}
	return (0);
}

void 	init_par(t_par *par, void *mlx)
{
	par->tex_no.img = NULL;
	par->tex_so.img = NULL;
	par->tex_we.img = NULL;
	par->tex_ea.img =NULL;
	par->tex_spr.img = NULL;
	par->floor= 0;
	par->ceil = 0;
	mlx_get_screen_size(mlx, &(par->rez.width), &(par->rez.height));
	par->map_i.map = NULL;
}

int		main(int argc, char **argv)
{
	t_par		par;
	ERROR_CODE	is_error;
	t_mlx 		mlx;

	if ((mlx.mlx = mlx_init()) == NULL)
		return (catch_error(ERROR_MLX_DO_NOT_START));
	if ((is_error = arg_check(argc, argv)) != 0)
		return (catch_error(is_error));
	init_par(&par, mlx.mlx);
	if ((is_error = read_map_file(&par, *(argv + 1), mlx.mlx)) != 0)
		return (catch_error(is_error));
	if ((argc == 3) && ((is_error = screen(&par, &mlx)) != 0))
		return (catch_error(is_error));
	if ((is_error = draw(&par, &mlx)) != 0)
		return (catch_error(is_error));
	return (0);
}
