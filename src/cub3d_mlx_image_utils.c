#include "cub3d.h"
#include "cub3d_draw.h"

void	ft_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->buff + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void ft_mlx_put_line(t_draw_data *data, t_vline *line, int x_ray)
{
	char	*start;
	int		x_step;
	int		counter;

	counter = 0;
	x_step = data->img.bits_per_pixel / 8;
	start = data->img.buff + x_step * x_ray;
	while (counter < line->drawStart)
	{
		*(unsigned int*)start = data->par.ceil;
		++counter;
		start += data->img.line_length;
	}
	while (counter < line->drawEnd)
	{
		*(unsigned int*)start = 0x000000FF;
		++counter;
		start += data->img.line_length;
	}
	while (counter < data->par.rez.height)
	{
		*(unsigned int*)start = data->par.floor;
		++counter;
		start += data->img.line_length;
	}
}
