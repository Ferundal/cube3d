#include "cub3d_parcer.h"

ERROR_CODE	read_map_file(t_par *par, char *file)
{
	int			fd;
	ERROR_CODE	is_error;

	fd = open(file, O_RDONLY);
	is_error = read_par(fd, par);
	if (is_error == 0)
		is_error = read_map(fd, par);
	close(fd);
	if (is_error != 0)
		return (catch_error(is_error));
	return (0);
}
