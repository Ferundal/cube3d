void	ft_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->buff + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void 	draw_background(t_img *data, t_par *par)
{
	char	*dst;
	int		half;
	int		counter;
	int		x_step;

	dst = data->buff;
	half = par->rez.height / 2;
	x_step = data->bits_per_pixel / 8;
	counter = half * par->rez.width;
	while (counter > 0)
	{
		*(unsigned int*)dst = par->ceil;
		--counter;
		dst += x_step;
	}
	counter = (par->rez.height - half) * par->rez.width;
	while (counter > 0)
	{
		*(unsigned int*)dst = par->floor;
		--counter;
		dst += x_step;
	}
}