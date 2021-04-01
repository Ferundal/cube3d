#include "cub3d.h"

ERROR_CODE	read_par_no(char *str, t_par *par, void *mlx)
{
	if (ft_strncmp("NO", str, 2) != 0)
		return (-1);
	str += 2;
	while (*str == ' ')
		++str;
	if (*str != '\0')
	{
		par->tex_no.img = mlx_xpm_file_to_image(mlx, str, &par->tex_no.w, \
			&par->tex_no.h);
		if (par->tex_no.img != NULL)
		{
			par->tex_no.buff = mlx_get_data_addr(par->tex_no.img, \
				&par->tex_no.bits_per_pixel, \
				&par->tex_no.line_length, \
				&par->tex_no.endian);
			return (0);
		}
	}
	return (ERROR_TEX_NO_NOT_FOUND);
}

ERROR_CODE	read_par_so(char *str, t_par *par, void *mlx)
{
	if (ft_strncmp("SO", str, 2) != 0)
		return (-1);
	str += 2;
	while (*str == ' ')
		++str;
	if (*str != '\0')
	{
		par->tex_so.img = mlx_xpm_file_to_image(mlx, str, &par->tex_so.w, \
			&par->tex_so.h);
		if (par->tex_so.img != NULL)
		{
			par->tex_so.buff = mlx_get_data_addr(par->tex_so.img, \
				&par->tex_so.bits_per_pixel, \
				&par->tex_so.line_length, \
				&par->tex_so.endian);
			return (0);
		}
	}
	return (ERROR_TEX_SO_NOT_FOUND);
}

ERROR_CODE	read_par_we(char *str, t_par *par, void *mlx)
{
	if (ft_strncmp("WE", str, 2) != 0)
		return (-1);
	str += 2;
	while (*str == ' ')
		++str;
	if (*str != '\0')
	{
		par->tex_we.img = mlx_xpm_file_to_image(mlx, str, &par->tex_we.w, \
			&par->tex_we.h);
		if (par->tex_we.img != NULL)
		{
			par->tex_we.buff = mlx_get_data_addr(par->tex_we.img, \
				&par->tex_we.bits_per_pixel, \
				&par->tex_we.line_length, \
				&par->tex_we.endian);
			return (0);
		}
	}
	return (ERROR_TEX_WE_NOT_FOUND);
}

ERROR_CODE	read_par_ea(char *str, t_par *par, void *mlx)
{
	if (ft_strncmp("EA", str, 2) != 0)
		return (-1);
	str += 2;
	while (*str == ' ')
		++str;
	if (*str != '\0')
	{
		par->tex_ea.img = mlx_xpm_file_to_image(mlx, str, &par->tex_ea.w, \
			&par->tex_ea.h);
		if (par->tex_ea.img != NULL)
		{
			par->tex_ea.buff = mlx_get_data_addr(par->tex_ea.img, \
				&par->tex_ea.bits_per_pixel, \
				&par->tex_ea.line_length, \
				&par->tex_ea.endian);
			return (0);
		}
	}
	return (ERROR_TEX_EA_NOT_FOUND);
}

ERROR_CODE	read_par_spr(char *str, t_par *par, void *mlx)
{
	if (ft_strncmp("S", str, 1) != 0)
		return (-1);
	str += 2;
	while (*str == ' ')
		++str;
	if (*str != '\0')
	{
		par->tex_spr.img = mlx_xpm_file_to_image(mlx, str, &par->tex_spr.w, \
			&par->tex_spr.h);
		if (par->tex_spr.img != NULL)
		{
			par->tex_spr.buff = mlx_get_data_addr(par->tex_spr.img, \
				&par->tex_spr.bits_per_pixel, \
				&par->tex_spr.line_length, \
				&par->tex_spr.endian);
			return (0);
		}
	}
	return (ERROR_TEX_SPR_NOT_FOUND);
}
