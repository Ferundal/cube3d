#include "../headers/cub3d.h"

int		catch_error(ERROR_CODE err_code)
{
	char	err_msg;

	err_msg = '0' + err_code;
	write(1, &err_msg, 1);
	return (err_code);
}