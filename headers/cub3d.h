#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include "cub3d_errors.h"
# include "../libft/libft.h"

# define SCREEN_FLAG "––save"

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
	int			tex_no;
	int			tex_so;
	int			tex_we;
	int			tex_ea;
	int			tex_spr;
	t_color		floor;
	t_color		ceil;
	t_map_i		map_i;
}				t_par;

int		catch_error(int err_code);
int		read_map_file(t_par *par, char *file);
int		screen(t_par *par);
int		draw(t_par *par);

#endif