#include <math.h>

#include "cub3d.h"
#include "cub3d_draw.h"
#include "cub3d_math.h"
#include "cub3d_map.h"

int raycast(t_par *par, t_img *img, t_mlx *mlx, t_data *data)
{
	 //initial direction vector
	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	for(int x = 0; x < par->rez.width; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)par->rez.width - 1; //x-coordinate in camera space
		double rayDirX = data->dirX + data->planeX * cameraX;
		double rayDirY = data->dirY + data->planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)data->posX;
		int mapY = (int)data->posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = d_abs(1 / rayDirX);
		double deltaDistY = d_abs(1 / rayDirY);
		double perpWallDist;

			//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
			//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (data->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (data->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->posY) * deltaDistY;
		}
			//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
				//Check if ray has hit a wall
			if(get_map_value(par->map_i, mapX, mapY) == '1')
				hit = 1;
		}
			//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if(side == 0) perpWallDist = (mapX - data->posX + (1 - stepX) / 2) / rayDirX;
		else          perpWallDist = (mapY - data->posY + (1 - stepY) / 2) / rayDirY;

			//Calculate height of line to draw on screen
		int lineHeight = (int)(par->rez.height / perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + par->rez.height / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + par->rez.height / 2;
		if(drawEnd >= par->rez.height)drawEnd = par->rez.height - 1;

        color = 0x0000FF00;


			//draw the pixels of the stripe as a vertical line
		verLine(x, drawStart, drawEnd, color);
	}


		double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
		double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
		//move forward if no wall in front of you
	}
}


