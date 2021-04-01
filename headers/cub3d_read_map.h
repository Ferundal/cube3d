#ifndef CUB3D_READ_MAP_H
# define CUB3D_READ_MAP_H

# include "cub3d_errors.h"

# define FLAG_STORE int

# define FLAG_WALL (1 << 0)
# define FLAG_SPACE (1 << 1)
# define FLAG_PLAYER (1 << 2)

ERROR_CODE		map_lc_check(char *str, FLAG_STORE *flags);
ERROR_CODE		map_check(t_par *par);

#endif
