#ifndef CUB3D_PARCER_H
# define CUB3D_PARCER_H

# include "cub3d.h"
# include "flag_utils.h"
# include <stdlib.h>

int		read_par(int fd, t_par *par, void *mlx);
int		read_par_res(char *str, t_par *par, FLAG_STORE *p);
int		read_par_no(char *str, t_par *par, void *mlx);
int		read_par_so(char *str, t_par *par, void *mlx);
int		read_par_we(char *str, t_par *par, void *mlx);
int		read_par_ea(char *str, t_par *par, void *mlx);
int		read_par_spr(char *str, t_par *par, void *mlx);
int		read_par_colors(char *str, t_par *par, FLAG_STORE *p);
int		read_map(int fd, t_par *par);

#endif
