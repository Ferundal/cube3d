#include "cub3d.h"
#include "cub3d_draw.h"
#include <math.h>
#include <stdlib.h>

void	sort_sprites(t_draw_data *data)
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
			if (max->dist < (data->spr_arr.arr + in_counter)->dist )
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

void	set_dist(t_draw_data *data)
{
	int			counter;
	t_sprite 	*temp;

	temp = data->spr_arr.arr;
	counter = 0;
	while (counter < data->spr_arr.size)
	{
		temp->dist = ((data->posX - temp->x) * (data->posX - temp->x) +
				(data->posY - temp->y) * (data->posY - temp->y));
		++temp;
		++counter;
	}
}

void	find_sprite_pos(t_draw_data *data, t_sprites *temp, int counter)
{
	temp->spriteX = (data->spr_arr.arr + counter)->x - data->posX;
	temp->spriteY = (data->spr_arr.arr + counter)->y - data->posY;
	temp->invDet = 1.0 / (data->planeX * data->dirY - data->dirX * data->planeY);
	temp->transformX = temp->invDet * (data->dirY * temp->spriteX - data->dirX * temp->spriteY);
	temp->transformY = temp->invDet * (-data->planeY * temp->spriteX + data->planeX * temp->spriteY);
	temp->spriteScreenX = (int)((data->par.rez.width / 2) * (1 + temp->transformX / temp->transformY));
}

void	find_sprite_size(t_draw_data *data, t_sprites *temp)
{
	temp->spriteHeight = abs((int) (data->par.rez.height / (temp->transformY)));
	temp->drawStartY = -temp->spriteHeight / 2 + data->par.rez.height / 2;
	if(temp->drawStartY < 0) temp->drawStartY = 0;
	temp->drawEndY = temp->spriteHeight / 2 + data->par.rez.height / 2;
	if(temp->drawEndY >= data->par.rez.height) temp->drawEndY = data->par.rez.height - 1;
	temp->spriteWidth = abs( (int) (data->par.rez.height / (temp->transformY)));
	temp->drawStartX = -temp->spriteWidth / 2 + temp->spriteScreenX;
	if(temp->drawStartX < 0) temp->drawStartX = 0;
	temp->drawEndX = temp->spriteWidth / 2 + temp->spriteScreenX;
	if(temp->drawEndX >= data->par.rez.width) temp->drawEndX = data->par.rez.width - 1;
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
