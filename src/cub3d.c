/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:37:20 by cjettie           #+#    #+#             */
/*   Updated: 2021/04/01 15:44:18 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_draw.h"
#include <stdlib.h>

ERROR_CODE	cub3d_exit(t_draw_data *data, ERROR_CODE is_error)
{
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	catch_error(is_error);
	exit (0);
}

static ERROR_CODE	arg_check(int argc, char **argv)
{
	int		len;
	int		f_len;

	if ((argc < 2) || (argc > 3))
		return (ERROR_WRONG_ARG_AMT);
	len = ft_strlen(*(argv + 1));
	if (len < 5)
		return (ERROR_WRONG_FIRST_ARG);
	f_len = ft_strlen(FILE_F);
	if (ft_strncmp(*(argv + 1) + len - f_len, FILE_F, f_len) != 0)
		return (ERROR_WRONG_FIRST_ARG);
	if (argc == 3)
	{
		len = ft_strlen(SCREEN_FLAG);
		if ((ft_strncmp(*(argv + 2), SCREEN_FLAG, len) != 0) || \
				(*(*(argv + 2) + len) != '\0'))
			return (ERROR_WRONG_SECOND_ARG);
	}
	return (0);
}

static void	init_par(t_par *par, void *mlx, int is_screen)
{
	par->tex_no.img = NULL;
	par->tex_so.img = NULL;
	par->tex_we.img = NULL;
	par->tex_ea.img = NULL;
	par->tex_spr.img = NULL;
	par->floor = 0;
	par->ceil = 0;
	if (is_screen == 0)
		mlx_get_screen_size(mlx, &(par->rez.w), &(par->rez.h));
	else
	{
		par->rez.w = 2147483647;
		par->rez.h = 2147483647;
	}
	par->map_i.map = NULL;
	par->map_i.h = 0;
	par->map_i.w = 0;
}

int	main(int argc, char **argv)
{
	t_par		par;
	ERROR_CODE	is_error;
	t_mlx		mlx;

	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		return (catch_error(ERROR_MLX_DO_NOT_START));
	is_error = arg_check(argc, argv);
	if (is_error == 0)
		init_par(&par, mlx.mlx, argc - 2);
	if (is_error == 0)
		is_error = read_map_file(&par, *(argv + 1), mlx.mlx);
	if ((is_error == 0) && (argc == 3))
		is_error = screen(&par, &mlx);
	if ((is_error == 0) && (argc == 2))
		is_error = draw(&par, &mlx);
	catch_error(is_error);
	return (0);
}
