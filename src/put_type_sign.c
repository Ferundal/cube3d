/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:54:54 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/21 16:03:49 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#define DEC_B_S "0123456789"
#define DEC_B_L 10

static int		put_int_first_sign(long long int arg, t_arg_par *par)
{
	if ((is_f(par, F_JUSTIFY) == 1) || ((is_f(par, F_JUSTIFY) == 0)
	&& (is_f(par, F_ZEROFILL) == 1) && is_f(par, F_PRECIS) != 1))
	{
		if (arg < 0)
		{
			ft_putchar_fd('-', FD);
			return (1);
		}
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

static int		put_int_second_sign(long long int arg, t_arg_par *par)
{
	if ((is_f(par, F_JUSTIFY) == 0)
	&& ((is_f(par, F_ZEROFILL) == 0) || (is_f(par, F_PRECIS) == 1)))
	{
		if (arg < 0)
		{
			return (ft_put_char_c_fd('-', FD));
		}
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

static int		is_need_sign(long long int arg, t_arg_par *par)
{
	if (arg < 0)
		return (1);
	if (is_f(par, F_SHOW_PLUS) == 1)
		return (1);
	if (is_f(par, F_SHOW_SPC) == 1)
		return (1);
	return (0);
}

long long int	get_sign_arg(t_arg_par *par, va_list argptr)
{
	if (is_f(par, F_SIZE_LL))
		return ((long long int)va_arg(argptr, long long int));
	if (is_f(par, F_SIZE_L))
		return ((long int)va_arg(argptr, long int));
	if (is_f(par, F_SIZE_H))
		return ((short)va_arg(argptr, int));
	if (is_f(par, F_SIZE_HH))
		return ((char)va_arg(argptr, int));
	return (va_arg(argptr, int));
}

void			put_type_int(va_list argptr, t_arg_par *par, int *print_amt)
{
	long long int	arg;
	int				f_amt;
	int				arg_len;

	if (is_f(par, F_PRECIS) == 0)
		par->precis = 1;
	arg = get_sign_arg(par, argptr);
	arg_len = sign_int_nbr_amt_base(arg, DEC_B_L);
	f_amt = par->width - find_prc(par, arg_len) - is_need_sign(arg, par);
	*print_amt += put_int_first_sign(arg, par);
	if (is_f(par, F_JUSTIFY) == 0)
	{
		if ((is_f(par, F_ZEROFILL) == 1) && (is_f(par, F_PRECIS) != 1))
			*print_amt += put_fillers(f_amt, '0');
		else
			*print_amt += put_fillers(f_amt, ' ');
	}
	*print_amt += put_int_second_sign(arg, par);
	*print_amt += put_sign_int_nbr_base_prc(arg, par, DEC_B_S, FD);
	if (is_f(par, F_JUSTIFY) == 1)
		*print_amt += put_fillers(f_amt, ' ');
}
