#include "cub3d_parcer.h"

int 	read_par_texturies(char *str, t_par *par, FLAG_STORE *p)
{
	ERROR_CODE	read_status;

	read_status = 0;
	if (is_f(p, FLAG_TEX_NO) == 0)
		if ((read_status = read_par_no(str, par)) == 0)
			set_f(p, FLAG_TEX_NO, 1);
	if ((read_status < 1) && (is_f(p, FLAG_TEX_SO) == 0))
		if ((read_status = read_par_so(str, par)) == 0)
			set_f(p, FLAG_TEX_SO, 1);
	if ((read_status < 1) && (is_f(p, FLAG_TEX_WE) == 0))
		if ((read_status = read_par_we(str, par)) == 0)
			set_f(p, FLAG_TEX_WE, 1);
	if ((read_status < 1) && (is_f(p, FLAG_TEX_EA) == 0))
		if ((read_status = read_par_ea(str, par)) == 0)
			set_f(p, FLAG_TEX_EA, 1);
	if ((read_status < 1) && (is_f(p, FLAG_TEX_SPR) == 0))
		if ((read_status = read_par_spr(str, par)) == 0)
			set_f(p, FLAG_TEX_SPR, 1);
	return (read_status)
}

int		read_par(int fd, t_par *par)
{
	int			line_status;
	char		*curr_line;
	FLAG_STORE	p;
	FLAG_STORE	temp;
	ERROR_CODE	read_status;

	while ((line_status = get_next_line(fd, &curr_line)) == 1)
	{
		if ((*curr_line != '\0'))
		{
			if (is_f(&p, FLAG_REZ) == 0)
				if ((read_status = read_res(curr_line, par)) == 0)
					set_f(&p, FLAG_REZ, 1);
			if (read_status < 0)
				read_status = read_par_texturies(curr_line, par, &p);
			if (read_status < 0)
				read_status =

		}
		free(curr_line);
	}
}