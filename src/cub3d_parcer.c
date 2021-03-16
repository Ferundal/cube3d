#include "cub3d_parcer.h"

int		read_map_file(t_par *par, char *file)
{
	int			fd;
	ERROR_CODE	is_error;

	fd = open(file, O_RDONLY);
	if ((is_error = read_par(fd, par)) != 0)
		return (catch_error(is_error));
	if ((is_error = read_map(fd, par) != 0)
		return (catch_error(is_error));
	return (0);
}
