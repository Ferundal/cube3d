#include "cub3d.h"
#include "cub3d_draw.h"

void	ft_mlx_put_text(int *counter, \
						t_draw_data *data, \
						t_line *line, \
						char **start)
{
	double	step;
	double	text_pos;
	int		texY;

	if (*counter < line->draw_end)
	{
		step = 1.0 * line->text.h / line->line_height;
		text_pos = ((line->line_height / 2 - data->par.rez.h / 2) + \
					line->draw_start) * step;
		while (*counter < line->draw_end)
		{
			texY = (int)text_pos;
			if (texY == line->text.h)
				texY -= 1;
			text_pos += step;
			**(int **)start = *(int *)(line->text.buff + \
				line->tex_x * (line->text.bits_per_pixel / 8) + \
				line->text.line_length * texY);
			(*counter) += 1;
			*start += data->img.line_length;
		}
	}
}

void	ft_mlx_put_ceil(int *counter, \
						t_draw_data *data, \
						t_line *line, \
						char **start)
{
	while (*counter < line->draw_start)
	{
		**(int **)start = data->par.ceil;
		(*counter) += 1;
		*start += data->img.line_length;
	}
}

void	ft_mlx_put_floor(int *counter, t_draw_data *data, char **start)
{
	while (*counter < data->par.rez.h)
	{
		**(int **)start = data->par.floor;
		(*counter) += 1;
		*start += data->img.line_length;
	}
}

void	ft_mlx_put_tex_line(t_draw_data *data, t_line *line, int x_ray)
{
	char	*start;
	int		counter;

	counter = 0;
	start = data->img.buff + x_ray * (data->img.bits_per_pixel / 8);
	ft_mlx_put_ceil(&counter, data, line, &start);
	ft_mlx_put_text(&counter, data, line, &start);
	ft_mlx_put_floor(&counter, data, &start);
}
