#include "cube3d_map.h"

void		move_forward(t_map_i map_i, keyDown(SDLK_UP))
{
	if(get_map_value(map_i, (int)(posX + dirX * moveSpeed), (int)posY) != '1')
		data->posX += data->dirX * moveSpeed;
	if(get_map_value(map_i, (int)posX, (int)(posY + dirY * moveSpeed)) != '1')
		data->posY += data->dirY * moveSpeed;
}

void		move_backward(t_map_i map_i, keyDown(SDLK_DOWN))
{
	if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false)
		data->posX -= data->dirX * moveSpeed;
	if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false)
		data->posY -= data->dirY * moveSpeed;
}

void		rotate_right(keyDown(SDLK_RIGHT))
{
	double	temp;

	temp = data->dirX;
	data->dirX = data->dirX * cos(-rotSpeed) - data->dirY * sin(-rotSpeed);
	data->dirY = temp * sin(-rotSpeed) + data->dirY * cos(-rotSpeed);
	temp = data->planeX;
	data->planeX = data->planeX * cos(-rotSpeed) - data->planeY * sin(-rotSpeed);
	data->planeY = temp * sin(-rotSpeed) + data->planeY * cos(-rotSpeed);
}

void		rotate_left(keyDown(SDLK_LEFT))
{
	double	temp;

	temp = data->dirX;
	data->dirX = data->dirX * cos(rotSpeed) - data->dirY * sin(rotSpeed);
	data->dirY = temp * sin(rotSpeed) + data->dirY * cos(rotSpeed);
	temp = data->planeX;
	data->planeX = data->planeX * cos(rotSpeed) - data->planeY * sin(rotSpeed);
	data->planeY = temp * sin(rotSpeed) + data->planeY * cos(rotSpeed);
}
