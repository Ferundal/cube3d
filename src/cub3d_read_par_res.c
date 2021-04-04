#include "cub3d.h"
#include "cub3d_atoi.h"
#include "cub3d_parcer.h"

ERROR_CODE	read_res(char *str, t_par *par)
{
	if (*str != 'R')
		return (-1);
	++str;
	while (*str == ' ')
		str++;
	par->rez.w = cub3d_atoi(&str, par->rez.w);
	if (par->rez.w < 1)
		return (ERROR_WRONG_PAR_REZ);
	while (*str == ' ')
		str++;
	par->rez.h = cub3d_atoi(&str, par->rez.h);
	if (par->rez.h < 1)
		return (ERROR_WRONG_PAR_REZ);
	if (*str == '\0')
		return (0);
	return (ERROR_WRONG_PAR_REZ);
}

ERROR_CODE	read_par_res(char *str, t_par *par, t_flags *p)
{
	ERROR_CODE	read_status;

	read_status = -1;
	if (p->rez == 0)
	{
		read_status = read_res(str, par);
		if (read_status == 0)
			p->rez = 1;
	}
	return (read_status);
}
