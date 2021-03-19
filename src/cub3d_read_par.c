#include "cub3d_parcer.h"
#include "cub3d_read_par.h"
#include "get_next_line.h"

ERROR_CODE	read_par_texturies(char *str, t_par *par, FLAG_STORE *p)
{
	ERROR_CODE	read_status;

	read_status = -1;
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
	return (read_status);
}

FLAG_STORE  all_flags(void)
{
    FLAG_STORE  result;

    result = 0;
    set_f(&result, FLAG_REZ, 1);
    set_f(&result, FLAG_TEX_NO, 1);
    set_f(&result, FLAG_TEX_SO, 1);
    set_f(&result, FLAG_TEX_WE, 1);
    set_f(&result, FLAG_TEX_EA, 1);
    set_f(&result, FLAG_TEX_SPR, 1);
    set_f(&result, FLAG_FLOOR, 1);
    return (result);
}

ERROR_CODE	read_par(int fd, t_par *par)
{
	char		*curr_line;
	FLAG_STORE	p;
	ERROR_CODE	read_status;
	int 		line_status;

	p = 0;
	while (p != all_flags())
	{
		line_status = get_next_line(fd, &curr_line);
		read_status = read_par_res(curr_line, par, &p);
		if (read_status < 0)
			read_status = read_par_texturies(curr_line, par, &p);
		if (read_status < 0)
			read_status = read_par_colors(curr_line, par, &p);
		if ((read_status < 0) && (*curr_line != '\0'))
			read_status = ERROR_NOT_A_PAR;
		free(curr_line);
		if (read_status > 0)
		    return (read_status);
		if (line_status == 0)
			return (ERROR_NOT_ALL_INFO);
	}
	return (0);
}