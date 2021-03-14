/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:05:30 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/21 16:06:29 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#define DEC_B_S "0123456789"
#define DEC_B_L 10

static int	put_uns_first_sign(t_arg_par *par)
{
	if ((is_f(par, F_JUSTIFY) == 1) || ((is_f(par, F_JUSTIFY) == 0)
		&& (is_f(par, F_ZEROFILL) == 1) && is_f(par, F_PRECIS) != 1))
	{
		if (is_f(par, F_SHOW_PLUS) == 1)
		{
			ft_putchar_fd('+', FD);
			return (1);
		}
		if (is_f(par, F_SHOW_SPC) == 1)
		{
			ft_putchar_fd(' ', FD);
			return (1);
		}
	}
	return (0);
}

static int	put_uns_second_sign(t_arg_par *par)
{
	if ((is_f(par, F_JUSTIFY) == 0)
		&& ((is_f(par, F_ZEROFILL) == 0) || (is_f(par, F_PRECIS) == 1)))
	{
		if (is_f(par, F_SHOW_PLUS) == 1)
		{
			return (ft_put_char_c_fd('+', FD));
		}
		if (is_f(par, F_SHOW_SPC) == 1)
		{
			return (ft_put_char_c_fd(' ', FD));
		}
	}
	return (0);
}

static int	uns_need_sign(t_arg_par *par)
{
	if (is_f(par, F_SHOW_PLUS) == 1)
		return (1);
	if (is_f(par, F_SHOW_SPC) == 1)
		return (1);
	return (0);
}

void		put_type_uns(va_list argptr, t_arg_par *par, int *prt_amt)
{
	unsigned long long int	arg;
	int						f_amt;
	int						arg_len;

	if (is_f(par, F_PRECIS) == 0)
		par->precis = 1;
	arg = get_uns_arg(par, argptr);
	arg_len = uns_int_nbr_amt_base(arg, DEC_B_L);
	f_amt = par->width - find_prc(par, arg_len) - uns_need_sign(par);
	*prt_amt += put_uns_first_sign(par);
	if (is_f(par, F_JUSTIFY) == 0)
	{
		if ((is_f(par, F_ZEROFILL) == 1) && (is_f(par, F_PRECIS) != 1))
			*prt_amt += put_fillers(f_amt, '0');
		else
			*prt_amt += put_fillers(f_amt, ' ');
	}
	*prt_amt += put_uns_second_sign(par);
	*prt_amt += put_uns_int_nbr_base_prc(arg, par, DEC_B_S, FD);
	if (is_f(par, F_JUSTIFY) == 1)
		*prt_amt += put_fillers(f_amt, ' ');
}
