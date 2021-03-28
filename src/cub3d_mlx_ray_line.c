#include "cub3d.h"
#include "cub3d_draw.h"

void	ft_mlx_put_text(int *counter, t_draw_data *data, t_line *line, char **start)
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
			**(int**)start = *(int*)(line->text.buff +
					line->texX * (line->text.bits_per_pixel / 8) + line->text.line_length * texY);
			(*counter) += 1;
			*start += data->img.line_length;
		}
	}
}

void	ft_mlx_put_ceil(int *counter, t_draw_data *data, t_line *line, char **start)
{
	while (*counter < line->drawStart)
	{
		**(int**)start = data->par.ceil;
		(*counter) += 1;
		*start += data->img.line_length;
	}
}

void	ft_mlx_put_floor(int *counter, t_draw_data *data, char **start)
{

	while (*counter < data->par.rez.height)
	{
		**(int**)start = data->par.floor;
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
