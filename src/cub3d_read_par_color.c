#include "cub3d.h"
#include "cub3d_atoi.h"
#include "cub3d_parcer.h"

static ERROR_CODE 	read_color (char **str, t_color *color)
{
	color->r = cub3d_atoi_l(str, 256);
	if (color->r < 0)
		return (1);
	while (**str == ' ')
		*str += 1;
	if (**str != ',')
		return (1);
	*str += 1;
	while (**str == ' ')
		*str += 1;
	color->g = cub3d_atoi_l(str, 256);
	if (color->g < 0)
		return (1);
	while (**str == ' ')
		*str += 1;
	if (**str != ',')
		return (1);
	*str += 1;
	while (**str == ' ')
		*str += 1;
	color->b = cub3d_atoi_l(str, 256);
	if (color->b < 0)
		return (1);
	return (0);
}

static ERROR_CODE	read_color_floor (char *str, t_par *par)
{
	t_color	t_color;

	while (*str == ' ')
		str++;
	if (*str != 'F')
		return (-1);
	++str;
	while (*str == ' ')
		++str;
	if (read_color(&str, &t_color) != 0)
		return (ERROR_WRONG_PAR_FLOOR);
	if (*str != '\0')
		return (ERROR_WRONG_PAR_FLOOR);
	par->floor = (t_color.r << 16 | t_color.g << 8 | t_color.b);
	return (0);
}

static ERROR_CODE	read_color_ceil (char *str, t_par *par)
{
	t_color	t_color;

	while (*str == ' ')
		str++;
	if (*str != 'C')
		return (-1);
	++str;
	while (*str == ' ')
		++str;
	if (read_color(&str, &t_color) != 0)
		return (ERROR_WRONG_PAR_CEIL);
	par->ceil = (t_color.r << 16 | t_color.g << 8 | t_color.b);
	if (*str != '\0')
		return (ERROR_WRONG_PAR_CEIL);
	return (0);
}

ERROR_CODE	read_par_colors (char *str, t_par *par, t_flags *p)
{
	ERROR_CODE	read_status;

	read_status = -1;
	if (p->floor == 0)
	{
		read_status = read_color_floor(str, par);
		if (read_status == 0)
			p->floor = 1;
	}
	if ((read_status < 0) && (p->ceil == 0))
	{
		read_status = read_color_ceil(str, par);
		if (read_status == 0)
			p->ceil = 1;
	}
	return (read_status);
}
