#ifndef CUB3D_PARCER_H
# define CUB3D_PARCER_H

# include "cub3d.h"
# include "flag_utils.h"
# include <stdlib.h>

int		read_res(char *str, t_par *par);
int 	read_par_no(char *str, t_par *par);
int 	read_par_so(char *str, t_par *par);
int 	read_par_we(char *str, t_par *par);
int 	read_par_ea(char *str, t_par *par);
int 	read_par_spr(char *str, t_par *par);
int     read_par_colors (char *str, t_par *par);

# define FLAG_STORE int

# define FLAG_REZ (1 << 0)
# define FLAG_TEX_NO (1 << 1)
# define FLAG_TEX_SO (1 << 2)
# define FLAG_TEX_WE (1 << 3)
# define FLAG_TEX_EA (1 << 4)
# define FLAG_TEX_SPR (1 << 5)
# define FLAG_FLOOR (1 << 6)
# define FLAG_CEIL (1 << 7)

#endif
