/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:17:28 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/21 16:20:43 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	put_arg(const char **str, va_list argptr, int *print_amt)
{
	t_arg_par	par;

	par.f = 0;
	par.width = 0;
	par.precis = 0;
	while (read_flags(str, &par) == 1)
	{
	}
	if (read_width(str, &par, argptr) != 0)
		return (1);
	if (**str == '.')
	{
		*str += 1;
		if (read_precis(str, &par, argptr) != 0)
			return (1);
	}
	if (read_size(str, &par) != 0)
		return (1);
	if (put_if_type(str, &par, argptr, print_amt) == 0)
	{
		return (0);
	}
	*str -= 1;
	return (1);
}
