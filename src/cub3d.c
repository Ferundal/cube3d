#include "cub3d.h"

int		arg_check(int argc, char **argv)
{
	if ((argc < 2) || (argc > 3))
		return (ERROR_WRONG_ARG_AMT);
	if ((argc == 3) &&
		(ft_strncmp(*(argv + 2), SCREEN_FLAG, ft_strlen(*(argv + 2)))))
		return (ERROR_WRONG_SECOND_ARG);
	return (0);
}

void 	init_par(t_par *par, void *mlx)
{
	par->tex_no = NULL;
	par->tex_so = NULL;
	par->tex_we = NULL;
	par->tex_ea =NULL;
	par->tex_spr = NULL;
	mlx_get_screen_size(mlx, &(par->rez.width), &(par->rez.height));
	par->map_i.map = NULL;
}

int		main(int argc, char **argv)
{
	t_par		par;
	ERROR_CODE	is_error;
	void 		*mlx;

	if ((mlx = mlx_init()) == NULL)
		return (catch_error(ERROR_MLX_DO_NOT_START));
	if ((is_error = arg_check(argc, argv)) != 0)
		return (catch_error(is_error));
	init_par(&par, mlx);
	if ((is_error = read_map_file(&par, *(argv + 1))) != 0)
		return (catch_error(is_error));
	if ((argc == 3) && ((is_error = screen(&par)) != 0))
		return (catch_error(is_error));
	if ((is_error = draw(&par)) != 0)
		return (catch_error(is_error));
	return (0);
}
