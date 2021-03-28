#ifndef CUB3D_DRAW_H
#define CUB3D_DRAW_H
#include "cub3d.h"

typedef struct	s_raycast
{
	int			x;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	int			stepX;
	int			stepY;
	int			side;
}				t_raycast;

typedef struct	s_line
{
	t_text		text;
	int			texX;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
}				t_line;

typedef struct	s_sprites
{
	double		spriteX;
	double		spriteY;
	double		invDet;
	double		transformX;
	double		transformY;
	int			spriteScreenX;
	int			spriteHeight;
	int			drawStartY;
	int			drawEndY;
	int			spriteWidth;
	int			drawStartX;
	int			drawEndX;
	int			texX;
	int			texY;
}				t_sprites;

ERROR_CODE		draw_frame(t_draw_data *data);

void			raycast(t_draw_data *data);
t_text			text_switch(t_draw_data *data, t_raycast *temp);

void			ft_mlx_put_tex_line(t_draw_data *data, t_line *line, int x_ray);
int				key_press(int keycode, t_draw_data *data);
int				key_unpress(int keycode, t_draw_data *data);
int 			exit_pressed(int keycode, t_draw_data *data);


int 			move_calc(t_draw_data *data);

void			move_forward(t_draw_data *data);
void			move_backward(t_draw_data *data);
void			move_right(t_draw_data *p);
void			move_left(t_draw_data *p);
void			rotate_right(t_draw_data *data);
void			rotate_left(t_draw_data *data);

void			draw_sprites(t_draw_data *data);
void			ft_mlx_put_spr_line(t_draw_data *data,
									t_sprites *temp, t_sprite *spr);
#endif
