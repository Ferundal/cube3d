#include "cub3d.h"
#include "cub3d_draw.h"

void	ft_mlx_put_text(int *counter, t_draw_data *data, t_line *line, int **start)
{
	double	step;
	double	text_pos;
	int		texY;

	if (*counter < line->drawEnd)
	{
		step = 1.0 * line->text.height / line->lineHeight;
		text_pos = ((line->lineHeight / 2 - data->par.rez.height / 2) +
					line->drawStart) * step;
		while (*counter < line->drawEnd)
		{
			texY = (int)text_pos;
			if (texY == line->text.height)
				texY -= 1;
			text_pos += step;
			**start = *(line->text.buff +
					line->texX + line->text.width * texY);
			(*counter) += 1;
			*start += data->par.rez.width;
		}
	}
}

void	ft_mlx_put_ceil(int *counter, t_draw_data *data, t_line *line, int **start)
{
	while (*counter < line->drawStart)
	{
		**start = data->par.ceil;
		(*counter) += 1;
		*start += data->par.rez.width;
	}
}

void	ft_mlx_put_floor(int *counter, t_draw_data *data, int **start)
{
	while (*counter < data->par.rez.height)
	{
		**start = data->par.floor;
		(*counter) += 1;
		*start += data->par.rez.width;
	}
}

void	ft_mlx_put_tex_line(t_draw_data *data, t_line *line, int x_ray)
{
	int		*start;
	int		counter;

	counter = 0;
	start = data->img.buff + x_ray;
	ft_mlx_put_ceil(&counter, data, line, &start);
	ft_mlx_put_text(&counter, data, line, &start);
	ft_mlx_put_floor(&counter, data, &start);
}
