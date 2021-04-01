#ifndef CUB3D_DRAW_H
# define CUB3D_DRAW_H
# include "cub3d.h"

typedef struct s_raycast
{
	int			x;
	double		camera_x;
	double		r_dir_x;
	double		r_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	int			side;
}				t_raycast;

typedef struct s_line
{
	t_text		text;
	int			tex_x;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_line;

typedef struct s_sprites
{
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			sprite_height;
	int			draw_start_y;
	int			draw_end_y;
	int			sprite_width;
	int			draw_start_x;
	int			draw_end_x;
	int			tex_x;
	int			tex_y;
}				t_sprites;

typedef struct s_bmp_header
{
	short		file_type;
	int			file_size;
	short		reserved_1;
	short		reserved_2;
	int			pixel_data_offset;
	int			header_size;
	int			image_width;
	int			image_height;
	short		planes;
	short		bit_per_pixel;
	int			compression;
	int			image_size;
	int			x_pixels_per_meter;
	int			y_pixels_per_meter;
	int			total_colors;
	int			important_colors;
}				t_bmp_header;

ERROR_CODE		draw_frame(t_draw_data *data);
ERROR_CODE		init_data(t_draw_data *data);

void			raycast(t_draw_data *data);
t_text			text_switch(t_draw_data *data, t_raycast *temp);

void			ft_mlx_put_tex_line(t_draw_data *data, t_line *line, int x_ray);
int				key_press(int keycode, t_draw_data *data);
int				key_unpress(int keycode, t_draw_data *data);
int				exit_pressed(t_draw_data *data);

int				move_calc(t_draw_data *data);

void			move_forward(t_draw_data *data);
void			move_backward(t_draw_data *data);
void			move_right(t_draw_data *p);
void			move_left(t_draw_data *p);
void			rotate_right(t_draw_data *data);
void			rotate_left(t_draw_data *data);

void			draw_sprites(t_draw_data *data);

void			ft_mlx_put_spr_line(t_draw_data *data, \
									t_sprites *temp, t_sprite *spr);
#endif
