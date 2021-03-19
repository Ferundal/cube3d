# include "cub3d.h"

ERROR_CODE	read_par_no(char *str, t_par *par)
{
	if (ft_strncmp("NO", str, 2) != 0)
		return (-1);
	str += 2;
	while (*str == ' ')
		++str;
	if (*str != '\0') {
		par->tex_no = open(str, O_RDONLY);
		if (par->tex_no == -1)
			return (ERROR_TEX_NO_NOT_FOUND);
		return (0);
	}
	return (ERROR_TEX_NO_NOT_FOUND);
}

ERROR_CODE	read_par_so(char *str, t_par *par)
{
	if (ft_strncmp("SO", str, 2) != 0)
		return (-1);
	str += 2;
	while (*str == ' ')
		++str;
	if (*str != '\0') {
		par->tex_so = open(str, O_RDONLY);
		if (par->tex_so == -1)
			return (ERROR_TEX_SO_NOT_FOUND);
		return (0);
	}
	return (ERROR_TEX_SO_NOT_FOUND);
}

ERROR_CODE	read_par_we(char *str, t_par *par)
{
	if (ft_strncmp("WE", str, 2) != 0)
		return (-1);
	str += 2;
	while (*str == ' ')
		++str;
	if (*str != '\0') {
		par->tex_we = open(str, O_RDONLY);
		if (par->tex_we == -1)
			return (ERROR_TEX_WE_NOT_FOUND);
		return (0);
	}
	return (ERROR_TEX_WE_NOT_FOUND);
}

ERROR_CODE	read_par_ea(char *str, t_par *par)
{
	if (ft_strncmp("EA", str, 2) != 0)
		return (-1);
	str += 2;
	while (*str == ' ')
		++str;
	if (*str != '\0') {
		par->tex_ea = open(str, O_RDONLY);
		if (par->tex_ea == -1)
			return (ERROR_TEX_EA_NOT_FOUND);
		return (0);
	}
	return (ERROR_TEX_EA_NOT_FOUND);
}

ERROR_CODE	read_par_spr(char *str, t_par *par)
{
	if (ft_strncmp("S", str, 2) != 0)
		return (-1);
	str += 2;
	while (*str == ' ')
		++str;
	if (*str != '\0') {
		par->tex_spr = open(str, O_RDONLY);
		if (par->tex_spr == -1)
			return (ERROR_TEX_SPR_NOT_FOUND);
		return (0);
	}
	return (ERROR_TEX_SPR_NOT_FOUND);
}