#include "cub3d.h"
#include "cub3d_draw.h"
#include "cub3d_errors.h"
#include <stdlib.h>

void	screen_init(t_draw_data *data, t_bmp_header *header)
{
	*((char *)&header->file_type) = 'B';
	*((char *)&header->file_type + 1) = 'M';
	header->file_size = 54 + (int) sizeof(int) \
	* data->par.rez.h * data->par.rez.w;
	header->reserved_1 = 0;
	header->reserved_2 = 0;
	header->pixel_data_offset = 54;
	header->header_size = 40;
	header->image_width = data->par.rez.w;
	header->image_height = -data->par.rez.h;
	header->planes = 1;
	header->bit_per_pixel = data->img.bits_per_pixel;
	header->compression = 0;
	header->image_size = \
		sizeof(int) * data->par.rez.h * data->par.rez.w;
	header->x_pixels_per_meter = 0;
	header->y_pixels_per_meter = 0;
	header->total_colors = 0;
	header->important_colors = 0;
}

void	write_header(int fd, t_bmp_header *header)
{
	write(fd, &header->file_type, sizeof (header->file_type));
	write(fd, &header->file_size, sizeof (header->file_size));
	write(fd, &header->reserved_1, sizeof (header->reserved_1));
	write(fd, &header->reserved_2, sizeof (header->reserved_2));
	write(fd, &header->pixel_data_offset, sizeof (header->pixel_data_offset));
	write(fd, &header->header_size, sizeof (header->header_size));
	write(fd, &header->image_width, sizeof (header->image_width));
	write(fd, &header->image_height, sizeof (header->image_height));
	write(fd, &header->planes, sizeof (header->planes));
	write(fd, &header->bit_per_pixel, sizeof (header->bit_per_pixel));
	write(fd, &header->compression, sizeof (header->compression));
	write(fd, &header->image_size, sizeof (header->image_size));
	write(fd, &header->x_pixels_per_meter, sizeof (header->x_pixels_per_meter));
	write(fd, &header->y_pixels_per_meter, sizeof (header->y_pixels_per_meter));
	write(fd, &header->total_colors, sizeof (header->total_colors));
	write(fd, &header->important_colors, sizeof (header->important_colors));
}

ERROR_CODE	write_screen(t_draw_data *data, t_bmp_header *bmp_h)
{
	int		fd;

	fd = open("screen.bmp", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0666);
	if (fd == -1)
		return (ERROR_CANT_CREATE_SCREEN_FILE);
	write_header(fd, bmp_h);
	write(fd, data->img.buff, \
	sizeof(int) * data->par.rez.h * data->par.rez.w);
	close(fd);
	return (0);
}

ERROR_CODE	screen(t_par *par, t_mlx *mlx)
{
	ERROR_CODE		is_error;
	t_draw_data		data;
	t_bmp_header	bmp_header;

	data.mlx = *mlx;
	data.par = *par;
	data.z_buff = malloc(sizeof(double) * par->rez.w);
	data.img.buff = malloc(sizeof(int) * data.par.rez.w * data.par.rez.h);
	if ((data.z_buff != NULL) || (data.img.buff != NULL))
	{
		data.img.bits_per_pixel = 32;
		data.img.line_length = data.par.rez.w * sizeof(int);
		is_error = init_data(&data);
		if ((is_error) != 0)
			return (is_error);
		raycast(&data);
		draw_sprites(&data);
		screen_init(&data, &bmp_header);
		write_screen(&data, &bmp_header);
	}
	free(data.z_buff);
	free(data.img.buff);
	if ((data.z_buff == NULL) || (data.img.buff == NULL))
		return (ERROR_CAN_NOT_ALLOCATE_MEMORY);
	return (0);
}
