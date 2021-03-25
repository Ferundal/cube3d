
#include "cub3d.h"
#include "cub3d_draw.h"
#include "cub3d_math.h"
#include "cub3d_map.h"

void	raycast_init_values(t_draw_data *data, t_raycast *temp)
{
	temp->cameraX = 2 * temp->x / (double)data->par.rez.width - 1;
	temp->rayDirX = data->dirX + data->planeX * temp->cameraX;
	temp->rayDirY = data->dirY + data->planeY * temp->cameraX;
	temp->mapX = (int)data->posX;
	temp->mapY = (int)data->posY;
	temp->deltaDistX = d_abs(1 / temp->rayDirX);
	temp->deltaDistY = d_abs(1 / temp->rayDirY);
}

void	raycast_find_steps(t_draw_data *data, t_raycast *temp)
{
	if(temp->rayDirX < 0)
	{
		temp->stepX = -1;
		temp->sideDistX = (data->posX - temp->mapX) * temp->deltaDistX;
	}
	else
	{
		temp->stepX = 1;
		temp->sideDistX = (temp->mapX + 1.0 - data->posX) * temp->deltaDistX;
	}
	if(temp->rayDirY < 0)
	{
		temp->stepY = -1;
		temp->sideDistY = (data->posY - temp->mapY) * temp->deltaDistY;
	}
	else
	{
		temp->stepY = 1;
		temp->sideDistY = (temp->mapY + 1.0 - data->posY) * temp->deltaDistY;
	}
}

void	raycast_find_hit(t_draw_data *data, t_raycast *temp)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if(temp->sideDistX < temp->sideDistY)
		{
			temp->sideDistX += temp->deltaDistX;
			temp->mapX += temp->stepX;
			temp->side = 0;
		}
		else
		{
			temp->sideDistY += temp->deltaDistY;
			temp->mapY += temp->stepY;
			temp->side = 1;
		}
		if(get_map_value(data->par.map_i, temp->mapX, temp->mapY) == '1')
			hit = 1;
	}
}

void	raycast_draw_line(t_draw_data *data, t_raycast *temp)
{
	double	perpWallDist;
	t_line	line;

	if(temp->side == 0)
		perpWallDist = (temp->mapX - data->posX + (1 - temp->stepX) / 2) / temp->rayDirX;
	else
		perpWallDist = (temp->mapY - data->posY + (1 - temp->stepY) / 2) / temp->rayDirY;
	line.lineHeight = (int)(data->par.rez.height / perpWallDist);
	line.drawStart = -line.lineHeight / 2 + data->par.rez.height / 2;
	if(line.drawStart < 0)
		line.drawStart = 0;
	line.drawEnd = line.lineHeight / 2 + data->par.rez.height / 2;
	if(line.drawEnd >= data->par.rez.height)
		line.drawEnd = data->par.rez.height - 1;
	ft_mlx_put_line(data, &line, temp->x);
}

void	raycast(t_draw_data *data)
{
	t_raycast temp;

	temp.x = 0;
	while(temp.x < data->par.rez.width)
	{
		raycast_init_values(data, &temp);
		raycast_find_steps(data, &temp);
		raycast_find_hit(data, &temp);
		raycast_draw_line(data, &temp);
		++temp.x;
	}
}


