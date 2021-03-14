/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:14:45 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/21 18:57:21 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	read_size_l(const char **str, t_arg_par *par)
{
	if (**str == 'l')
	{
		*str += 1;
		if (**str == 'l')
		{
			*str += 1;
			set_f(par, F_SIZE_LL, 1);
			return (1);
		}
		else
		{
			set_f(par, F_SIZE_L, 1);
			return (1);
		}
	}
	return (0);
}

static int	read_size_h(const char **str, t_arg_par *par)
{
	if (**str == 'h')
	{
		*str += 1;
		if (**str == 'h')
		{
			*str += 1;
			set_f(par, F_SIZE_HH, 1);
			return (1);
		}
		else
		{
			set_f(par, F_SIZE_H, 1);
			return (1);
		}
	}
	return (0);
}

int			read_size(const char **str, t_arg_par *par)
{
	if (read_size_l(str, par) == 1)
		return (0);
	if (read_size_h(str, par) == 1)
		return (0);
	return (0);
}
