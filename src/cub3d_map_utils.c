#include "cub3d.h"

char		get_map_value(t_map_i map_i, int x, int y)
{
	char 		*temp_str;

	if ((x > map_i.width) || (y > map_i.height))
		return (-1);
	temp_str = *(map_i.map + y);
	while (x > 0)
	{
		if ((*temp_str) == '\0')
			return (' ');
		--x;
		++temp_str;
	}
	return (*temp_str);
}

int 		find_map_value(char *value, t_map_i map_i, int *x, int *y)
{
	char 	*temp;
	char 	temp_c;

	*y = 0;
	while (*y < map_i.height)
	{
		*x = 0;
		while (*x < map_i.width)
		{
			temp = value;
			temp_c = get_map_value(map_i, *x, *y);
			while (*temp != '\0')
			{
				if (temp_c == *temp)
					return (0);
				++temp;
			}
			*x += 1;
		}
		*y += 1;
	}
	return (1);
}