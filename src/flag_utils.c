/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:28:15 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/13 12:46:11 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	set_f(t_arg_par *par, FLAG_STORE flag, char value)
{
	if (value == 0)
		par->f = par->f & (~flag);
	else
		par->f = par->f | flag;
}

int		is_f(t_arg_par *par, FLAG_STORE flag)
{
	if ((par->f & flag) == 0)
		return (0);
	return (1);
}

int		read_flags(const char **str, t_arg_par *par)
{
	if (**str == '0')
	{
		set_f(par, F_ZEROFILL, 1);
		*str += 1;
		return (1);
	}
	if (**str == '-')
	{
		set_f(par, F_JUSTIFY, 1);
		*str += 1;
		return (1);
	}
	if (**str == '+')
	{
		set_f(par, F_SHOW_PLUS, 1);
		*str += 1;
		return (1);
	}
	if (**str == ' ')
	{
		set_f(par, F_SHOW_SPC, 1);
		*str += 1;
		return (1);
	}
	return (0);
}
