int 	cub3d_atoi(char **str, int max)
{
	int 	result;
	int 	max_result;
	int 	max_num;

	if (!((**str >= '0') && (**str <= '9')))
		return (-1);
	result = 0;
	max_result = max / 10;
	max_num = max % 10;
	while ((**str >= '0') && (**str <= '9'))
	{
		if ((result < max_result) ||
			((result == max_result) && (**str - '0' <= max_num )))
		{
			result = result * 10 + (**str - '0');
			(*str) += 1;
		}
		else
			break;
	}
	while ((**str >= '0') && (**str <= '9'))
		(*str) += 1;
	return (result);
}

int 	cub3d_atoi_l(char **str, int max)
{
	int 	result;

	result = cub3d_atoi(str, max);
	if (result == max)
		return (-1);
	return (result);
}