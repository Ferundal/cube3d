#include "cub3d.h"
#include "cub3d_draw.h"
#include <math.h>
#include <stdlib.h>

static void	sort_sprites(t_draw_data *data)
{
	int			ex_counter;
	int			in_counter;
	t_sprite	*max;
	t_sprite	temp;

	ex_counter = 0;
	while (ex_counter < data->spr_arr.size)
	{
		max = data->spr_arr.arr + ex_counter;
		in_counter = ex_counter + 1;
		while (in_counter < data->spr_arr.size)
		{
			if (max->dist < (data->spr_arr.arr + in_counter)->dist)
			{
				temp = *max;
				*max = *(data->spr_arr.arr + in_counter);
				*(data->spr_arr.arr + in_counter) = temp;
			}
			++in_counter;
		}
		++ex_counter;
	}
}

static void	set_dist(t_draw_data *data)
{
	int			counter;
	t_sprite	*temp;

	temp = data->spr_arr.arr;
	counter = 0;
	while (counter < data->spr_arr.size)
	{
		temp->dist = ((data->pos_x - temp->x) * (data->pos_x - temp->x) + \
				(data->pos_y - temp->y) * (data->pos_y - temp->y));
		++temp;
		++counter;
	}
}

static void	find_sprite_pos(t_draw_data *data, t_sprites *temp, int counter)
{
	temp->sprite_x = (data->spr_arr.arr + counter)->x - data->pos_x;
	temp->sprite_y = (data->spr_arr.arr + counter)->y - data->pos_y;
	temp->inv_det = 1.0 / \
		(data->plane_x * data->dir_y - data->dir_x * data->plane_y);
	temp->transform_x = temp->inv_det * \
		(data->dir_y * temp->sprite_x - data->dir_x * temp->sprite_y);
	temp->transform_y = temp->inv_det * \
		(-data->plane_y * temp->sprite_x + data->plane_x * temp->sprite_y);
	temp->sprite_screen_x = (int)((data->par.rez.w / 2) \
	* (1 + temp->transform_x / temp->transform_y));
}

static void	find_sprite_size(t_draw_data *data, t_sprites *temp)
{
	temp->sprite_height = \
		abs((int)(data->par.rez.h / (temp->transform_y)));
	temp->draw_start_y = -temp->sprite_height / 2 + data->par.rez.h / 2;
	if (temp->draw_start_y < 0)
		temp->draw_start_y = 0;
	temp->draw_end_y = temp->sprite_height / 2 + data->par.rez.h / 2;
	if (temp->draw_end_y >= data->par.rez.h)
		temp->draw_end_y = data->par.rez.h - 1;
	temp->sprite_width = abs((int)(data->par.rez.w / (temp->transform_y)));
	temp->draw_start_x = -temp->sprite_width / 2 + temp->sprite_screen_x;
	if (temp->draw_start_x < 0)
		temp->draw_start_x = 0;
	temp->draw_end_x = temp->sprite_width / 2 + temp->sprite_screen_x;
	if (temp->draw_end_x > data->par.rez.w)
		temp->draw_end_x = data->par.rez.w;
}

void	draw_sprites(t_draw_data *data)
{
	t_sprites	temp;
	int			counter;

	set_dist(data);
	sort_sprites(data);
	counter = 0;
	while (counter < data->spr_arr.size)
	{
		find_sprite_pos(data, &temp, counter);
		find_sprite_size(data, &temp);
		ft_mlx_put_spr_line(data, &temp, data->spr_arr.arr + counter);
		++counter;
	}
}
