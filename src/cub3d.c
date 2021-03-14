#include "../headers/cub3d.h"

int		arg_check(int argc, char **argv)
{
	if ((argc < 2) || (argc > 3))
		return (ERROR_WRONG_ARG_AMT);
	if ((argc == 3) &&
		(ft_strncmp(*(argv + 2), SCREEN_FLAG, ft_strlen(ft_strlen))))
		return (ERROR_WRONG_SECOND_ARG);
	return (0);
}

int		main(int argc, char **argv)
{
	t_par		par;
	ERROR_CODE	is_error;

	if ((is_error = arg_check(argc, argv)) != 0)
		return (catch_error(is_error));
	if ((is_error = read_map_file(&par, *(argv + 1))) != 0)
		return (catch_error(is_error));
	if (argc == 3) && ((is_error = screen(&par)) != 0))
		return (catch_error(is_error));
	if ((is_error = draw(&par)) != 0)
		return (catch_error(is_error));
	return (0);
}
