//
// Created by Cetheres Jettie on 3/20/21.
//

#ifndef CUB3D_MAP_H
# define CUB3D_MAP_H
char		get_map_value(t_map_i map_i, int x, int y);
int			find_map_value(char *value, t_map_i map_i, int *x, int *y);
ERROR_CODE	map_check_flow(t_map_i *map);
ERROR_CODE	ft_flow(t_map_i *map, int x, int y);
int			find_all(char *value, t_map_i map_i, t_spr_arr *spr_arr);

#endif
