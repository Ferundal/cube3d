#include "cub3d_draw.h"
#include "mlx.h"

int	move_calc(t_draw_data *data)
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
	draw_frame(data);
	return (0);
}

int	key_press(int keycode, t_draw_data *data)
{
	if (keycode == 53)
		cub3d_exit(data, 0);
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
	return (0);
}

int	key_unpress(int keycode, t_draw_data *data)
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
	return (0);
}

int	exit_pressed(t_draw_data *data)
{
	cub3d_exit(data, 0);
	return (0);
}
