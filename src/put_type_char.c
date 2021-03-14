/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:04:14 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/21 16:07:48 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void		put_known_char(char arg, t_arg_par *par, int *print_amt)
{
	char	filler;

	filler = ' ';
	if ((is_f(par, F_JUSTIFY) == 0) && (is_f(par, F_ZEROFILL) == 1))
		filler = '0';
	if (is_f(par, F_JUSTIFY) == 1)
	{
		ft_putchar_fd(arg, FD);
		*print_amt += 1;
		*print_amt += put_fillers(par->width - 1, filler);
	}
	else
	{
		*print_amt += put_fillers(par->width - 1, filler);
		ft_putchar_fd(arg, FD);
		*print_amt += 1;
	}
}

void			put_type_char(va_list argptr, t_arg_par *par, int *prt_amt)
{
	char	arg;

	arg = va_arg(argptr, int);
	put_known_char(arg, par, prt_amt);
}

void			put_type_char_pct(t_arg_par *par, int *prt_amt)
{
	char	arg;

	arg = '%';
	put_known_char(arg, par, prt_amt);
}
