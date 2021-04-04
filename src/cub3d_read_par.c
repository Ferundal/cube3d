#include "cub3d_parcer.h"
#include "get_next_line.h"

ERROR_CODE	text_switch_1(char *str, t_par *par, t_flags *p, void *mlx)
{
	ERROR_CODE	read_status;

	read_status = -1;
	if (p->text_no == 0)
	{
		read_status = read_par_no(str, par, mlx);
		if (read_status == 0)
			p->text_no = 1;
	}
	if ((read_status < 0) && (p->text_so == 0))
	{
		read_status = read_par_so(str, par, mlx);
		if (read_status == 0)
			p->text_so = 1;
	}
	if ((read_status < 0) && (p->text_we == 0))
	{
		read_status = read_par_we(str, par, mlx);
		if (read_status == 0)
			p->text_we = 1;
	}
	return (read_status);
}

ERROR_CODE	text_switch_2(char *str, t_par *par, t_flags *p, void *mlx)
{
	ERROR_CODE	read_status;

	read_status = -1;
	if (p->text_ea == 0)
	{
		read_status = read_par_ea(str, par, mlx);
		if (read_status == 0)
			p->text_ea = 1;
	}
	if ((read_status < 0) && (p->text_spr == 0))
	{
		read_status = read_par_spr(str, par, mlx);
		if (read_status == 0)
			p->text_spr = 1;
	}
	return (read_status);
}

ERROR_CODE	read_par_texturies(char *str, t_par *par, t_flags *p, void *mlx)
{
	ERROR_CODE	read_status;

	read_status = text_switch_1(str, par, p, mlx);
	if (read_status < 0)
		read_status = text_switch_2(str, par, p, mlx);
	return (read_status);
}

void	flags_init(t_flags *flags)
{
	flags->rez = 0;
	flags->text_no = 0;
	flags->text_so = 0;
	flags->text_we = 0;
	flags->text_ea = 0;
	flags->text_spr = 0;
	flags->ceil = 0;
	flags->floor = 0;
}

ERROR_CODE	read_par(int fd, t_par *par, void *mlx)
{
	char		*curr_line;
	t_flags		p;
	ERROR_CODE	read_status;
	int			line_status;

	flags_init(&p);
	while (p.rez == 0 || p.text_no == 0 || p.text_so == 0 || p.text_ea == 0 \
			|| p.text_we == 0 || p.text_spr == 0 || p.ceil == 0 || p.floor == 0)
	{
		line_status = get_next_line(fd, &curr_line);
		read_status = read_par_res(curr_line, par, &p);
		if (read_status < 0)
			read_status = read_par_texturies(curr_line, par, &p, mlx);
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
