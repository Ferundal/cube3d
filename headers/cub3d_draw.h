#ifndef CUB3D_DRAW_H
#define CUB3D_DRAW_H

typedef struct	s_img {
	void		*img;
	char		*buff;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_player {
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		moveSpeed;
	double		rotSpeed;
}				t_player;

typedef struct	s_data {
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
}				t_data;

raycast(t_par *par, t_img *img, t_mlx *mlx, t_player *player);


#endif
