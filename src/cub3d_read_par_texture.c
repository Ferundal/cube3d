# include "cub3d.h"

ERROR_CODE	read_par_no(char *str, t_par *par, void *mlx)
{
	if (ft_strncmp("NO", str, 2) != 0)
		return (-1);
	str += 2;
	while (*str == ' ')
		++str;
	if (*str != '\0')
	{
		par->tex_no.img = mlx_xpm_file_to_image(mlx, str, &par->tex_no.width, &par->tex_no.height);
		if (par->tex_no.img != NULL)
			return (0);
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
		par->tex_so.img = mlx_xpm_file_to_image(mlx, str, &par->tex_so.width, &par->tex_so.height);
		if (par->tex_so.img != NULL)
			return (0);
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
		par->tex_we.img = mlx_xpm_file_to_image(mlx, str, &par->tex_we.width, &par->tex_we.height);
		if (par->tex_we.img != NULL)
			return (0);
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
		par->tex_ea.img = mlx_xpm_file_to_image(mlx, str, &par->tex_ea.width, &par->tex_ea.height);
		if (par->tex_ea.img != NULL)
			return (0);
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
		par->tex_spr.img = mlx_xpm_file_to_image(mlx, str, &par->tex_spr.width, &par->tex_spr.height);
		if (par->tex_spr.img != NULL)
			return (0);
	}
	return (ERROR_TEX_SPR_NOT_FOUND);
}