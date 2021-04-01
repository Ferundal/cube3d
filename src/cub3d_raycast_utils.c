#include "cub3d_draw.h"

t_text	text_switch(t_draw_data *data, t_raycast *temp)
{
	if (temp->side == 0)
	{
		if (temp->step_x > 0)
			return (data->par.tex_ea);
		return (data->par.tex_we);
	}
	if (temp->step_y > 0)
		return (data->par.tex_so);
	return (data->par.tex_no);
}
