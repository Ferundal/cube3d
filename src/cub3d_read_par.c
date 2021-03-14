#include "cub3d_parcer.h"

int		read_par(int fd, t_par *par)
{
	int		status;
	char	*curr_line;

	while ((status = get_next_line (fd, &curr_line)) == 1)
}