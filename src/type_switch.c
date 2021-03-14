/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_switch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:53:19 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/21 18:58:13 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	type_switcher_1(const char **str, t_arg_par *par, va_list argptr,
					int *print_amt)
{
	if ((**str == 'd') || (**str == 'i'))
	{
		put_type_int(argptr, par, print_amt);
		return (0);
	}
	if (**str == 'c')
	{
		put_type_char(argptr, par, print_amt);
		return (0);
	}
	if (**str == 's')
	{
		put_type_str(argptr, par, print_amt);
		return (0);
	}
	if (**str == 'p')
	{
		put_type_pointer(argptr, par, print_amt);
		return (0);
	}
	return (1);
}

static int	type_switcher_2(t_arg_par *par, va_list argptr, const char **str,
					int *print_amt)
{
	if (**str == 'x')
	{
		put_type_hex_s(argptr, par, print_amt);
		return (0);
	}
	if (**str == 'X')
	{
		put_type_hex_l(argptr, par, print_amt);
		return (0);
	}
	if (**str == '%')
	{
		put_type_char_pct(par, print_amt);
		return (0);
	}
	if (**str == 'u')
	{
		put_type_uns(argptr, par, print_amt);
		return (0);
	}
	return (1);
}

int			put_if_type(const char **str, t_arg_par *par,
		va_list argptr, int *print_amt)
{
	if (type_switcher_1(str, par, argptr, print_amt) == 0)
		return (0);
	if (type_switcher_2(par, argptr, str, print_amt) == 0)
		return (0);
	return (1);
}
