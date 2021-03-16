#include "cub3d.h"
#include "cub3d_atoi.h"

int 	read_color (char **str, t_color *color)
{
	if ((color->r = cub3d_atoi_l(str, 256)) < 0)
		return (1);
	while (**str == ' ')
		*str += 1;
	if (**str != ',')
		return (1);
	*str += 1;
	while (**str == ' ')
		*str += 1;
	if ((color->g = cub3d_atoi_l(str, 256)) < 0)
		return (1);
	while (**str == ' ')
		*str += 1;
	if (**str != ',')
		return (1);
	*str += 1;
	while (**str == ' ')
		*str += 1;
	if ((color->b = cub3d_atoi_l(str, 256)) < 0)
		return (1);
	return (0)
}

int 	read_color_floor (char *str, t_par *par)
{
	if (*str != 'F')
		return (-1);
	++str;
	while (*str == ' ')
		++str;
	if (read_color(&str, &(par->floor)) != 0)
		return (ERROR_WRONG_PAR_FLOOR);
	return (0);
}

int 	read_color_ceil (char *str, t_par *par)
{
	if (*str != 'C')
		return (-1);
	++str;
	while (*str == ' ')
		++str;
	if (read_color(&str, &(par->ceil)) != 0)
		return (ERROR_WRONG_PAR_CEIL);
	return (0);
}