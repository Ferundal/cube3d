#include <math.h>
#include "cub3d.h"
#include "cub3d_map.h"
#include "cub3d_draw.h"

void	move_forward(t_draw_data *p)
{
	if (get_map_value(p->par.map_i, \
	(int)(p->pos_x + p->dir_x * 1.1 * p->m_speed), (int)p->pos_y) != '1')
		p->pos_x += p->dir_x * p->m_speed;
	if (get_map_value(p->par.map_i, (int)p->pos_x, \
	(int)(p->pos_y + p->dir_y * 1.1 * p->m_speed)) != '1')
		p->pos_y += p->dir_y * p->m_speed;
}

void	move_backward(t_draw_data *p)
{
	if (get_map_value(p->par.map_i, \
		(int)(p->pos_x - p->dir_x * 1.1 * p->m_speed), (int)p->pos_y) != '1')
		p->pos_x -= p->dir_x * p->m_speed;
	if (get_map_value(p->par.map_i, \
		(int)p->pos_x, (int)(p->pos_y - p->dir_y * 1.1 * p->m_speed)) != '1')
		p->pos_y -= p->dir_y * p->m_speed;
}

void	move_right(t_draw_data *p)
{
	if (get_map_value(p->par.map_i, \
		(int)(p->pos_x - p->dir_y * 1.1 * p->m_speed), (int)p->pos_y) != '1')
		p->pos_x -= p->dir_y * p->m_speed;
	if (get_map_value(p->par.map_i, \
	(int)p->pos_x, (int)(p->pos_y + p->dir_x * 1.1 * p->m_speed)) != '1')
		p->pos_y += p->dir_x * p->m_speed;
}

void	move_left(t_draw_data *p)
{
	if (get_map_value(p->par.map_i, \
		(int)(p->pos_x + p->dir_y * 1.1 * p->m_speed), (int)p->pos_y) != '1')
		p->pos_x += p->dir_y * p->m_speed;
	if (get_map_value(p->par.map_i, \
		(int)p->pos_x, (int)(p->pos_y - p->dir_x * 1.1 * p->m_speed)) != '1')
		p->pos_y -= p->dir_x * p->m_speed;
}
