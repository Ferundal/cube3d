#include <math.h>

#include "cub3d.h"
#include "cub3d_draw.h"
#include "cub3d_math.h"
#include "cub3d_map.h"

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

int raycast(t_par *par, t_img *img, t_mlx *mlx, t_player *player)
{
	 //initial direction vector
	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	for(int x = 0; x < par->rez.width; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)par->rez.width - 1; //x-coordinate in camera space
		double rayDirX = player->dirX + planeX * cameraX;
		double rayDirY = player->dirY + planeY * cameraX;
			//which box of the map we're in
		int mapX = (int)player->posX;
		int mapY = (int)player->posY;

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
			sideDistX = (player->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - player->posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (player->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - player->posY) * deltaDistY;
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
		if(side == 0) perpWallDist = (mapX - player->posX + (1 - stepX) / 2) / rayDirX;
		else          perpWallDist = (mapY - player->posY + (1 - stepY) / 2) / rayDirY;

			//Calculate height of line to draw on screen
		int lineHeight = (int)(par->rez.height / perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + par->rez.height / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + par->rez.height / 2;
		if(drawEnd >= par->rez.height)drawEnd = par->rez.height - 1;

			//choose wall color
		//ColorRGB color;
		/*
		switch(worldMap[mapX][mapY])
		{
			case 1:  color = RGB_Red;    break; //red
			case 2:  color = RGB_Green;  break; //green
			case 3:  color = RGB_Blue;   break; //blue
			case 4:  color = RGB_White;  break; //white
			default: color = RGB_Yellow; break; //yellow
		}
		*/

			//give x and y sides different brightness
		if(side == 1) {color = color / 2;}

			//draw the pixels of the stripe as a vertical line
		verLine(x, drawStart, drawEnd, color);
		}

		//speed modifiers
		double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
		double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
		readKeys();
		//move forward if no wall in front of you
		if(keyDown(SDLK_UP))
		{
			if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) player->posX += player->dirX * moveSpeed;
			if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) player->posY += player->dirY * moveSpeed;
		}
		//move backwards if no wall behind you
		if(keyDown(SDLK_DOWN))
		{
			if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) player->posX -= player->dirX * moveSpeed;
			if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) player->posY -= player->dirY * moveSpeed;
		}
		//rotate to the right
		if(keyDown(SDLK_RIGHT))
		{
			//both camera direction and camera plane must be rotated
			double oldDirX = player->dirX;
			player->dirX = player->dirX * cos(-rotSpeed) - player->dirY * sin(-rotSpeed);
			player->dirY = oldDirX * sin(-rotSpeed) + player->dirY * cos(-rotSpeed);
			double oldPlaneX = planeX;
			planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
			planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
		}
		//rotate to the left
		if(keyDown(SDLK_LEFT))
		{
			//both camera direction and camera plane must be rotated
			double oldDirX = player->dirX;
			player->dirX = player->dirX * cos(rotSpeed) - player->dirY * sin(rotSpeed);
			player->dirY = oldDirX * sin(rotSpeed) + player->dirY * cos(rotSpeed);
			double oldPlaneX = planeX;
			planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
			planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
		}
	}
}


