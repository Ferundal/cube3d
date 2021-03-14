/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:08:15 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/21 16:13:20 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#define HEX_S_B_S "0123456789abcdef"
#define HEX_S_B_L 16

#define PTR_PH "0x"

static int	put_ptr_first_sign(t_arg_par *par)
{
	if ((is_f(par, F_JUSTIFY) == 1) || ((is_f(par, F_JUSTIFY) == 0)
	&& (is_f(par, F_ZEROFILL) == 1) && is_f(par, F_PRECIS) != 1))
	{
		ft_putstr_fd(PTR_PH, FD);
		return (ft_strlen(PTR_PH));
	}
	return (0);
}

static int	put_ptr_second_sign(t_arg_par *par)
{
	if ((is_f(par, F_JUSTIFY) == 0)
	&& ((is_f(par, F_ZEROFILL) == 0) || (is_f(par, F_PRECIS) == 1)))
	{
		ft_putstr_fd(PTR_PH, FD);
		return (ft_strlen(PTR_PH));
	}
	return (0);
}

static int	ptr_need_sign(void)
{
	return (ft_strlen(PTR_PH));
}

void		put_type_pointer(va_list argptr, t_arg_par *par, int *prt_amt)
{
	intptr_t	arg;
	int			f_amt;
	int			arg_len;

	if (is_f(par, F_PRECIS) == 0)
		par->precis = 1;
	arg = va_arg(argptr, intptr_t);
	arg_len = uns_int_nbr_amt_base(arg, HEX_S_B_L);
	f_amt = par->width - find_prc(par, arg_len) - ptr_need_sign();
	*prt_amt += put_ptr_first_sign(par);
	if (is_f(par, F_JUSTIFY) == 0)
	{
		if ((is_f(par, F_ZEROFILL) == 1) && (is_f(par, F_PRECIS) != 1))
			*prt_amt += put_fillers(f_amt, '0');
		else
			*prt_amt += put_fillers(f_amt, ' ');
	}
	*prt_amt += put_ptr_second_sign(par);
	*prt_amt += put_uns_int_nbr_base_prc(arg, par, HEX_S_B_S, FD);
	if (is_f(par, F_JUSTIFY) == 1)
		*prt_amt += put_fillers(f_amt, ' ');
}
