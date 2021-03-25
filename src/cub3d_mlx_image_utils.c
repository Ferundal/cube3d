#include "cub3d.h"
#include "cub3d_draw.h"

void	ft_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->buff + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		ft_mlx_put_text(int *counter, t_draw_data *data, t_line *line, char **start)
{
	double	step;
	double	text_pos;
	int		texY;
	char	text_start;

	if (*counter < line->drawEnd)
	{
		line->text = data->par.tex_no;
		step = 1.0 * line->text.height / line->lineHeight;
		text_pos = ((line->lineHeight / 2 - data->par.rez.height / 2) +
					line->drawStart) * step;
		text_start = line->text.img + ;
		while (counter < line->drawEnd)
		{
			texY = (int)text_pos & (line->text.height - 1);
			text_pos += step;
			*(unsigned int *) start = line->text.
			(*counter) += 1;
			start += data->img.line_length;
		}
	}
}

void	ft_mlx_put_ceil(int *counter, t_draw_data *data, t_line *line, char **start)
{
	while (*counter < line->drawStart)
	{
		*((unsigned int*)(*start)) = data->par.ceil;
		(*counter) += 1;
		*start += data->img.line_length;
	}
}

void	ft_mlx_put_floor(int *counter, t_draw_data *data, char **start)
{
	while (*counter < data->par.rez.height)
	{
		*((unsigned int*)(*start)) = data->par.floor;
		(*counter) += 1;
		*start += data->img.line_length;
	}
}

void	ft_mlx_put_line(t_draw_data *data, t_line *line, int x_ray)
{
	char		*start;
	int			x_step;
	int			counter;

	counter = 0;
	x_step = data->img.bits_per_pixel / 8;
	start = data->img.buff + x_step * x_ray;
	ft_mlx_put_ceil(&counter, data, line, &start);
	ft_mlx_put_text(&counter, data, line, &start);
	ft_mlx_put_floor(&counter, data, &start);
}
