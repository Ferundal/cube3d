#include "cub3d.h"
#include "cub3d_errors.h"

void 		put_error_msg_1(ERROR_CODE err_code, int fd)
{
	if (err_code == ERROR_WRONG_ARG_AMT)
		ft_putstr_fd("Wrong argument amount", fd);
	if (err_code == ERROR_WRONG_SECOND_ARG)
		ft_putstr_fd("Wrong option", fd);
	if (err_code == ERROR_WRONG_PAR_REZ)
		ft_putstr_fd("Error while rezolution reading", fd);
	if (err_code == ERROR_TEX_NO_NOT_FOUND)
		ft_putstr_fd("Error while reading NO texture", fd);
	if (err_code == ERROR_TEX_SO_NOT_FOUND)
		ft_putstr_fd("Error while reading SO texture", fd);
	if (err_code == ERROR_TEX_WE_NOT_FOUND)
		ft_putstr_fd("Error while reading WE texture", fd);
	if (err_code == ERROR_TEX_EA_NOT_FOUND)
		ft_putstr_fd("Error while reading EA texture", fd);
	if (err_code == ERROR_TEX_SPR_NOT_FOUND)
		ft_putstr_fd("Error while reading S texture", fd);
	if (err_code == ERROR_WRONG_PAR_FLOOR)
		ft_putstr_fd("Error while reading floor color", fd);
	if (err_code == ERROR_WRONG_PAR_CEIL)
		ft_putstr_fd("Error while reading ceil color", fd);
	if (err_code == ERROR_NOT_A_PAR)
		ft_putstr_fd("Unknown data while reading parameters", fd);
	if (err_code == ERROR_NOT_ALL_INFO)
		ft_putstr_fd("Not enough data", fd);
}

void 		put_error_msg_2(ERROR_CODE err_code, int fd)
{
	if (err_code == ERROR_CAN_NOT_ALLOCATE_MEMORY)
		ft_putstr_fd("Can't allocate memory", fd);
	if (err_code == ERROR_TWO_PLAYERS_ON_MAP)
		ft_putstr_fd("Two or more players on the map", fd);
	if (err_code == ERROR_MAP_ERROR)
		ft_putstr_fd("Error while reading map", fd);
	if (err_code == ERROR_CANT_GET_MAP_LINE)
		ft_putstr_fd("No map data", 1);
	if (err_code == ERROR_NO_PLAYER_ON_MAP)
		ft_putstr_fd("No player start on map", fd);
	if (err_code == ERROR_MAP_NOT_CLOSED)
		ft_putstr_fd("Map is not closed", fd);
	if (err_code == ERROR_MLX_DO_NOT_START)
		ft_putstr_fd("MLX do not start", fd);
	if (err_code == ERROR_WRONG_FIRST_ARG)
		ft_putstr_fd("Wrong map file name", fd);
}

ERROR_CODE	catch_error(ERROR_CODE err_code)
{
	put_error_msg_1(err_code, 1);
	put_error_msg_2(err_code, 1);
	return (err_code);
}