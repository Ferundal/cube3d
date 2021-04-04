#include "cub3d.h"
#include "cub3d_draw.h"
#include <stdlib.h>

char	get_map_value(t_map_i map_i, int x, int y)
{
	char		*temp_str;

	if ((x > map_i.w) || (y > map_i.h))
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

int 	find_map_value(char *value, t_map_i map_i, int *x, int *y)
{
	char		*temp;
	char		temp_c;

	*y = 0;
	while (*y < map_i.h)
	{
		*x = 0;
		while (*x < map_i.w)
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
	return (0);
}

static int	add_spr(t_spr_arr *spr_arr, char value, int x, int y)
{
	t_spr_arr	temp;
	int			counter;

	temp.size = spr_arr->size + 1;
	temp.arr = (t_sprite *)malloc(sizeof (t_sprite) * temp.size);
	if (temp.arr == NULL)
		return (ERROR_CAN_NOT_ALLOCATE_MEMORY);
	counter = 0;
	while (counter < spr_arr->size)
	{
		*(temp.arr + counter) = *(spr_arr->arr + counter);
		++counter;
	}
	(*(temp.arr + counter)).x = x + 0.5;
	(*(temp.arr + counter)).y = y + 0.5;
	(*(temp.arr + counter)).type = value;
	if (spr_arr->size != 0)
		free(spr_arr->arr);
	spr_arr->arr = temp.arr;
	spr_arr->size = temp.size;
	temp.arr = NULL;
	return (0);
}

ERROR_CODE	find_all(char *value, t_map_i map_i, t_spr_arr *spr_arr)
{
	int			x;
	int			y;
	char		temp_c;
	ERROR_CODE	is_error;

	y = 0;
	while (y < map_i.h)
	{
		x = 0;
		while (x < map_i.w)
		{
			temp_c = get_map_value(map_i, x, y);
			if ((ft_strchr(value, temp_c) != NULL) && (temp_c != 0))
			{
				is_error = add_spr(spr_arr, temp_c, x, y);
				if (is_error != 0)
					return (is_error);
			}
			++x;
		}
		++y;
	}
	return (0);
}
