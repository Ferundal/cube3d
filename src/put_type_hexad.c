/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_hexad.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:48:02 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/21 15:50:35 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "utils.h"

#define HEX_S_B_S "0123456789abcdef"
#define HEX_S_B_L 16

#define HEX_L_B_S "0123456789ABCDEF"
#define HEX_L_B_L 16

static int	put_hex_first_sign(t_arg_par *par)
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

static int	put_hex_second_sign(t_arg_par *par)
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

static int	hex_need_sign(t_arg_par *par)
{
	if (is_f(par, F_SHOW_PLUS) == 1)
		return (1);
	if (is_f(par, F_SHOW_SPC) == 1)
		return (1);
	return (0);
}

void		put_type_hex_s(va_list argptr, t_arg_par *par, int *prt_amt)
{
	unsigned long long int	arg;
	int						f_amt;
	int						arg_len;

	if (is_f(par, F_PRECIS) == 0)
		par->precis = 1;
	arg = get_uns_arg(par, argptr);
	arg_len = uns_int_nbr_amt_base(arg, HEX_S_B_L);
	f_amt = par->width - find_prc(par, arg_len) - hex_need_sign(par);
	*prt_amt += put_hex_first_sign(par);
	if (is_f(par, F_JUSTIFY) == 0)
	{
		if ((is_f(par, F_ZEROFILL) == 1) && (is_f(par, F_PRECIS) != 1))
			*prt_amt += put_fillers(f_amt, '0');
		else
			*prt_amt += put_fillers(f_amt, ' ');
	}
	*prt_amt += put_hex_second_sign(par);
	*prt_amt += put_uns_int_nbr_base_prc(arg, par, HEX_S_B_S, FD);
	if (is_f(par, F_JUSTIFY) == 1)
		*prt_amt += put_fillers(f_amt, ' ');
}

void		put_type_hex_l(va_list argptr, t_arg_par *par, int *prt_amt)
{
	unsigned long long int	arg;
	int						f_amt;
	int						arg_len;

	if (is_f(par, F_PRECIS) == 0)
		par->precis = 1;
	arg = get_uns_arg(par, argptr);
	arg_len = uns_int_nbr_amt_base(arg, HEX_L_B_L);
	f_amt = par->width - find_prc(par, arg_len) - hex_need_sign(par);
	*prt_amt += put_hex_first_sign(par);
	if (is_f(par, F_JUSTIFY) == 0)
	{
		if ((is_f(par, F_ZEROFILL) == 1) && (is_f(par, F_PRECIS) != 1))
			*prt_amt += put_fillers(f_amt, '0');
		else
			*prt_amt += put_fillers(f_amt, ' ');
	}
	*prt_amt += put_hex_second_sign(par);
	*prt_amt += put_uns_int_nbr_base_prc(arg, par, HEX_L_B_S, FD);
	if (is_f(par, F_JUSTIFY) == 1)
		*prt_amt += put_fillers(f_amt, ' ');
}
