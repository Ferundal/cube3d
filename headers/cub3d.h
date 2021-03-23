#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include "cub3d_errors.h"
# include "libft.h"
# include "mlx.h"

# define SCREEN_FLAG "––save"
# define FILE_F ".cub"

typedef struct	s_rez
{
	int			height;
	int			width;
}				t_rez;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_map_i
{
	int			height;
	int			width;
	char		**map;
}				t_map_i;

typedef struct	s_par
{
	t_rez		rez;
	char*		tex_no;
	char*		tex_so;
	char*		tex_we;
	char*		tex_ea;
	char*		tex_spr;
	int 		floor;
	int 		ceil;
	t_map_i		map_i;
}				t_par;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_img {
	void		*img;
	char		*buff;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_keys
{
	int			m_forw;
	int			m_back;
	int			m_right;
	int			m_left;
	int			r_right;
	int			r_left;
}				t_keys;

typedef struct	s_draw_data
{
	t_mlx		mlx;
	t_par		par;
	t_img		img;
	t_keys		keys;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		moveSpeed;
	double		rotSpeed;
}				t_draw_data;

int			catch_error(int err_code);
int			read_map_file(t_par *par, char *file);
int			screen(t_par *par, t_mlx *mlx);
int			draw(t_par *par, t_mlx *mlx);
ERROR_CODE 	cub3d_exit(t_draw_data *date_);

#endif