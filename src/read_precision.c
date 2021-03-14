/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:06:50 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/21 19:17:32 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	prec_atoi(const char **str, int *result)
{
	char	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = sign * (-1);
		*str += 1;
	}
	while (ft_isdigit(**str))
	{
		*result = (*result * 10) + (**str - '0') * sign;
		*str += 1;
	}
	return (0);
}

int			read_precis(const char **str, t_arg_par *par, va_list argptr)
{
	set_f(par, F_PRECIS, 1);
	if (**str == '*')
	{
		par->precis = va_arg(argptr, int);
		*str += 1;
		return (0);
	}
	par->precis = 0;
	if (prec_atoi(str, &(par->precis)) != 0)
		return (1);
	return (0);
}
