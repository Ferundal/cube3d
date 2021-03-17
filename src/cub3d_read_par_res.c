#include "cub3d.h"
#include "cub3d_atoi.h"

int		read_res(char *str, t_par *par)
{
	if (*str != 'R')
		return (-1);
	++str;
	while (*str == ' ')
		str++;
	par->rez.width = cub3d_atoi(&str, par->rez.width);
	if (par->rez.width < 1)
		return (ERROR_WRONG_PAR_REZ);
	while (*str == ' ')
		str++;
	par->rez.height = cub3d_atoi(&str, par->rez.height);
	if (par->rez.height < 1)
		return (ERROR_WRONG_PAR_REZ);
	if (*str == '\0')
		return (0);
	return (ERROR_WRONG_PAR_REZ);
}

int     read_par_res(char *str, t_par *par, FLAG_STORE *p)
{

}