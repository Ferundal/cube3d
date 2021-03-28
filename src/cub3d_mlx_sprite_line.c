#include "cub3d.h"
#include "cub3d_draw.h"

t_text	*sprite_choose(t_draw_data *data, t_sprite *spr)
{
	if (spr->type == '2')
		return (&data->par.tex_spr);
	return (NULL);
}

void	ft_mlx_put_spr(t_draw_data *data, t_sprites *temp, t_text *c_text, char *start)
{
	int		y;
	int		t_color;

	y = temp->drawStartY;
	while (y < temp->drawEndY)
	{
		temp->texY = (int)((((double)y + ((double)temp->spriteHeight - (double)data->par.rez.height)  / 2) * (double)c_text->height) / (double)temp->spriteHeight);
		t_color = *(int*)(c_text->buff + temp->texX * (c_text->bits_per_pixel / 8) + (temp->texY * c_text->line_length));
		if (t_color != 0)
			*(int*)start = t_color;
		++y;
		start += data->img.line_length;
	}
}

void	ft_mlx_put_spr_line(t_draw_data *data, t_sprites *temp, t_sprite *spr)
{
	int		x;
	char	*start;
	t_text	*curr_text;

	curr_text = sprite_choose(data, spr);
	x = temp->drawStartX;
	while (x < temp->drawEndX)
	{
		temp->texX = (int)(((double)x - (-(double)temp->spriteWidth / 2 +
				(double)temp->spriteScreenX)) *
				(double)curr_text->width / (double)temp->spriteWidth);
		if(temp->transformY > 0 && x > 0 && x <
				data->par.rez.width && temp->transformY < *(data->z_buff + x))
		{
			start = data->img.buff + x * (data->img.bits_per_pixel / 8) + temp->drawStartY * data->img.line_length;
			ft_mlx_put_spr(data, temp, curr_text, start);
		}
		++x;
	}
}
