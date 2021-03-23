#include <math.h>
#include "cub3d.h"
#include "cub3d_map.h"
#include "cub3d_draw.h"


void		move_forward(t_draw_data *p)
{
	if(get_map_value(p->par.map_i, (int)(p->posX + p->dirX * p->moveSpeed), (int)p->posY) != '1')
		p->posX += p->dirX * p->moveSpeed;
	if(get_map_value(p->par.map_i, (int)p->posX, (int)(p->posY + p->dirY * p->moveSpeed)) != '1')
		p->posY += p->dirY * p->moveSpeed;
}

void		move_backward(t_draw_data *p)
{
	if(get_map_value(p->par.map_i, (int)(p->posX - p->dirX * p->moveSpeed), (int)p->posY) != '1')
		p->posX -= p->dirX * p->moveSpeed;
	if(get_map_value(p->par.map_i, (int)p->posX, (int)(p->posY - p->dirY * p->moveSpeed)) != '1')
		p->posY -= p->dirY * p->moveSpeed;
}
void			move_right(t_draw_data *p)
{
	if(get_map_value(p->par.map_i, (int)(p->posX + p->dirY * p->moveSpeed), (int)p->posY) != '1')
		p->posX += p->dirY * p->moveSpeed;
	if(get_map_value(p->par.map_i, (int)p->posX, (int)(p->posY - p->dirX * p->moveSpeed)) != '1')
		p->posY -= p->dirX * p->moveSpeed;
}

void			move_left(t_draw_data *p)
{
	if(get_map_value(p->par.map_i, (int)(p->posX - p->dirY * p->moveSpeed), (int)p->posY) != '1')
		p->posX -= p->dirY * p->moveSpeed;
	if(get_map_value(p->par.map_i, (int)p->posX, (int)(p->posY + p->dirX * p->moveSpeed)) != '1')
		p->posY += p->dirX * p->moveSpeed;
}