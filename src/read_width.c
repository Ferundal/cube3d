/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:13:44 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/21 18:57:43 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	width_atoi(const char **str, int *result)
{
	while (ft_isdigit(**str))
	{
		*result = (*result * 10) + (**str - '0');
		*str += 1;
	}
	return (0);
}

int			read_width(const char **str, t_arg_par *par, va_list argptr)
{
	if (**str == '*')
	{
		par->width = va_arg(argptr, int);
		if (par->width < 0)
		{
			par->width = -par->width;
			set_f(par, F_JUSTIFY, 1);
		}
		*str += 1;
		return (0);
	}
	par->width = 0;
	if (width_atoi(str, &(par->width)) != 0)
		return (1);
	return (0);
}
