#include "cub3d_draw.h"
#include "mlx.h"

void	move_calc(t_draw_data *data)
{
	if (data->keys.m_forw == 1)
		move_forward(data);
	if (data->keys.m_back == 1)
		move_backward(data);
	if (data->keys.m_right == 1)
		move_right(data);
	if (data->keys.m_left == 1)
		move_left(data);
	if (data->keys.r_right == 1)
		rotate_right(data);
	if (data->keys.r_left == 1)
		rotate_left(data);
}

int		key_press(int keycode, t_draw_data *data)
{
	if (keycode == 53)
		cub3d_exit(data);
	if (keycode == 13)
		data->keys.m_forw = 1;
	if (keycode == 1)
		data->keys.m_back = 1;
	if (keycode == 2)
		data->keys.m_right = 1;
	if (keycode == 0)
		data->keys.m_left = 1;
	if (keycode == 124)
		data->keys.r_right = 1;
	if (keycode == 123)
		data->keys.r_left = 1;
	move_calc(data);
	draw_frame(data);
	return (0);
}

int		key_unpress(int keycode, t_draw_data *data)
{
	if (keycode == 13)
		data->keys.m_forw = 0;
	if (keycode == 1)
		data->keys.m_back = 0;
	if (keycode == 2)
		data->keys.m_right = 0;
	if (keycode == 0)
		data->keys.m_left = 0;
	if (keycode == 124)
		data->keys.r_right = 0;
	if (keycode == 123)
		data->keys.r_left = 0;
	move_calc(data);
	draw_frame(data);
	return (0);
}

int 	exit_pressed(int keycode, t_draw_data *data)
{
	if (keycode == (keycode + 1) - 1)
		cub3d_exit(data);
	return (0);
}