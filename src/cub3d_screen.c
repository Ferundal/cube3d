#include "cub3d.h"
#include "cub3d_draw.h"
#include "cub3d_errors.h"
#include "cub3d_map.h"
#include <stdlib.h>

void		screen_init(t_draw_data *data, t_bmp_header *header)
{
	ft_strlcpy((char*)&(header->file_type), "BM", 2);
	header->file_size = 54 + (int)sizeof (int) * data->par.rez.height * data->par.rez.width;
	header->reserved_1 = 0;
	header->reserved_2 = 0;
	header->pixel_data_offset = 54;
	header->header_size = 40;
	header->image_width = data->par.rez.width;
	header->image_height = data->par.rez.height;
	header->planes = 1;
	header->bit_per_pixel = 4;
	header->compression = 0;
	header->image_size = (int)sizeof (int) * data->par.rez.height * data->par.rez.width;
	header->x_pixels_per_meter = 0;
	header->y_pixels_per_meter = 0;
	header->total_colors = 0;
	header->important_colors = 0;
}

ERROR_CODE	write_screen(t_draw_data *data, t_bmp_header *bmp_h)
{
	int		fd;

	fd = open("screen.bmp", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0666);
	if (fd == -1)
		return (ERROR_CANT_CREATE_SCREEN_FILE);
	write(fd, bmp_h, sizeof(t_bmp_header));
	write(fd, data->img.buff, sizeof (int) * data->par.rez.height * data->par.rez.width);
	close(fd);
	return (0);
}

ERROR_CODE	screen(t_par *par, t_mlx *mlx)
{
	ERROR_CODE		is_error;
	t_draw_data		data;
	double			z_buffer[par->rez.width];
	t_bmp_header	bmp_header;

	data.mlx = *mlx;
	data.par = *par;
	if((data.img.buff = malloc(sizeof(int) * data.par.rez.width * data.par.rez.height)) == NULL)
		return (ERROR_CAN_NOT_ALLOCATE_MEMORY);
	data.img.bits_per_pixel = 32;
	data.img.line_length = data.par.rez.width;
	if((is_error = init_data(&data)) != 0)
		return (is_error);
	data.z_buff = &z_buffer[0];
	raycast(&data);
	draw_sprites(&data);
	screen_init(&data, &bmp_header);
	write_screen(&data, &bmp_header);
	return (0);
}
