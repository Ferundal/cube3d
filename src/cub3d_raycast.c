#include "cub3d.h"
#include "cub3d_draw.h"
#include "cub3d_math.h"
#include "cub3d_map.h"

void	raycast_init_values(t_draw_data *data, t_raycast *temp)
{
	temp->camera_x = 2 * temp->x / (double)data->par.rez.w - 1;
	temp->r_dir_x = data->dir_x + data->plane_x * temp->camera_x;
	temp->r_dir_y = data->dir_y + data->plane_y * temp->camera_x;
	temp->map_x = (int)data->pos_x;
	temp->map_y = (int)data->pos_y;
	temp->delta_dist_x = d_abs(1 / temp->r_dir_x);
	temp->delta_dist_y = d_abs(1 / temp->r_dir_y);
}

void	raycast_find_steps(t_draw_data *data, t_raycast *temp)
{
	if (temp->r_dir_x < 0)
	{
		temp->step_x = -1;
		temp->side_dist_x = (data->pos_x - temp->map_x) * temp->delta_dist_x;
	}
	else
	{
		temp->step_x = 1;
		temp->side_dist_x = \
			(temp->map_x + 1.0 - data->pos_x) * temp->delta_dist_x;
	}
	if (temp->r_dir_y < 0)
	{
		temp->step_y = -1;
		temp->side_dist_y = (data->pos_y - temp->map_y) * temp->delta_dist_y;
	}
	else
	{
		temp->step_y = 1;
		temp->side_dist_y = \
			(temp->map_y + 1.0 - data->pos_y) * temp->delta_dist_y;
	}
}

void	raycast_find_hit(t_draw_data *data, t_raycast *temp)
{
	int			hit;

	hit = 0;
	while (hit == 0)
	{
		if (temp->side_dist_x < temp->side_dist_y)
		{
			temp->side_dist_x += temp->delta_dist_x;
			temp->map_x += temp->step_x;
			temp->side = 0;
		}
		else
		{
			temp->side_dist_y += temp->delta_dist_y;
			temp->map_y += temp->step_y;
			temp->side = 1;
		}
		if (get_map_value(data->par.map_i, temp->map_x, temp->map_y) == '1')
			hit = 1;
	}
}

void	raycast_draw_line(t_draw_data *data, t_raycast *t)
{
	double		perp_w_d;
	t_line		line;
	double		wallX;

	if (t->side == 0)
		perp_w_d = (t->map_x - data->pos_x + (1 - t->step_x) / 2) / t->r_dir_x;
	else
		perp_w_d = (t->map_y - data->pos_y + (1 - t->step_y) / 2) / t->r_dir_y;
	line.line_height = (int)(data->par.rez.h / perp_w_d);
	*(data->z_buff + t->x) = perp_w_d;
	line.draw_start = -line.line_height / 2 + data->par.rez.h / 2;
	if (line.draw_start < 0)
		line.draw_start = 0;
	line.draw_end = line.line_height / 2 + data->par.rez.h / 2;
	if (line.draw_end > data->par.rez.h)
		line.draw_end = data->par.rez.h;
	if (t->side == 0)
		wallX = data->pos_y + perp_w_d * t->r_dir_y;
	else
		wallX = data->pos_x + perp_w_d * t->r_dir_x;
	wallX -= (double)((int)wallX);
	line.text = text_switch(data, t);
	line.tex_x = (int)(wallX * (double)line.text.w);
	ft_mlx_put_tex_line(data, &line, t->x);
}

void	raycast(t_draw_data *data)
{
	t_raycast	temp;

	temp.x = 0;
	while (temp.x < data->par.rez.w)
	{
		raycast_init_values(data, &temp);
		raycast_find_steps(data, &temp);
		raycast_find_hit(data, &temp);
		raycast_draw_line(data, &temp);
		++temp.x;
	}
}
