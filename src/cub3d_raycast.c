#include <math.h>

#include "cub3d.h"
#include "cub3d_draw.h"
#include "cub3d_math.h"
#include "cub3d_map.h"

int raycast(t_par *par, t_img *img, t_mlx *mlx, t_player *player)
{
	t_data temp;

	for(int x = 0; x < par->rez.width; x++)
	{
		//calculate ray position and direction
		temp.cameraX = 2 * x / (double)par->rez.width - 1; //x-coordinate in camera space
		temp.rayDirX = player->dirX + player->planeX * temp.cameraX;
		temp.rayDirY = player->dirY + player->planeY * temp.cameraX;
		//which box of the map we're in
		temp.mapX = (int)player->posX;
		temp.mapY = (int)player->posY;

		//length of ray from one x or y-side to next x or y-side
		temp.deltaDistX = d_abs(1 / temp.rayDirX);
		temp.deltaDistY = d_abs(1 / temp.rayDirY);

			//what direction to step in x or y-direction (either +1 or -1)

		temp.hit = 0; //was there a wall hit?
		 //was a NS or a EW wall hit?
			//calculate step and initial sideDist
		if(temp.rayDirX < 0)
		{
			temp.stepX = -1;
			temp.sideDistX = (player->posX - temp.mapX) * temp.deltaDistX;
		}
		else
		{
			temp.stepX = 1;
			temp.sideDistX = (temp.mapX + 1.0 - player->posX) * temp.deltaDistX;
		}
		if(temp.rayDirY < 0)
		{
			temp.stepY = -1;
			temp.sideDistY = (player->posY - temp.mapY) * temp.deltaDistY;
		}
		else
		{
			temp.stepY = 1;
			temp.sideDistY = (temp.mapY + 1.0 - player->posY) * temp.deltaDistY;
		}
			//perform DDA
		while (temp.hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if(temp.sideDistX < temp.sideDistY)
			{
				temp.sideDistX += temp.deltaDistX;
				temp.mapX += temp.stepX;
				temp.side = 0;
			}
			else
			{
				temp.sideDistY += temp.deltaDistY;
				temp.mapY += temp.stepY;
				temp.side = 1;
			}
				//Check if ray has hit a wall
			if(get_map_value(par->map_i, temp.mapX, temp.mapY) == '1')
				temp.hit = 1;
		}
			//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if(temp.side == 0)
			temp.perpWallDist = (temp.mapX - player->posX + (1 - temp.stepX) / 2) / temp.rayDirX;
		else
			temp.perpWallDist = (temp.mapY - player->posY + (1 - temp.stepY) / 2) / temp.rayDirY;

			//Calculate height of line to draw on screen
		int lineHeight = (int)(par->rez.height / temp.perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + par->rez.height / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + par->rez.height / 2;
		if(drawEnd >= par->rez.height)drawEnd = par->rez.height - 1;

		color = 0x0000FF00;


			//draw the pixels of the stripe as a vertical line
		verLine(x, drawStart, drawEnd, color);
	}
}


