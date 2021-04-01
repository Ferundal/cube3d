#include "cub3d.h"
#include "cub3d_draw.h"

t_text	*sprite_choose(t_draw_data *data, t_sprite *spr)
{
	if (spr->type == '2')
		return (&data->par.tex_spr);
	return (NULL);
}

void	ft_mlx_put_spr(t_draw_data *data, \
						t_sprites *temp, t_text *c_text, char *start)
{
	int		y;
	int		t_color;

	y = temp->draw_start_y;
	while (y < temp->draw_end_y)
	{
		temp->tex_y = (int)((((double)y + ((double)temp->sprite_height - \
			(double)data->par.rez.h) / 2) * \
			(double)c_text->h) / (double)temp->sprite_height);
		if (temp->tex_y > c_text->h)
			temp->tex_y = c_text->h;
		t_color = *(int *)(c_text->buff + temp->tex_x * \
			(c_text->bits_per_pixel / 8) + \
			(temp->tex_y * c_text->line_length));
		if (t_color != 0)
			*(int *)start = t_color;
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
	x = temp->draw_start_x;
	while (x < temp->draw_end_x)
	{
		temp->tex_x = (int)(((double)x - (-(double)temp->sprite_width / 2 + \
							(double)temp->sprite_screen_x)) * \
							(double)curr_text->w / (double)temp->sprite_width);
		if (temp->tex_x > curr_text->w)
			temp->tex_x = curr_text->w;
		if (temp->transform_y > 0 && x > 0 && x < data->par.rez.w && \
				temp->transform_y < *(data->z_buff + x))
		{
			start = data->img.buff + x * (data->img.bits_per_pixel / 8) + \
				temp->draw_start_y * data->img.line_length;
			ft_mlx_put_spr(data, temp, curr_text, start);
		}
		++x;
	}
}
