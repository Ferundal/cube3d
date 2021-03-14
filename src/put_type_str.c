/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:16:16 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/21 16:17:07 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#define NULL_PLACEHOLDER "(null)"

static int	put_str_c_fd(char *str, int str_len)
{
	int		prt_amn;

	prt_amn = 0;
	while (str_len > 0)
	{
		ft_putchar_fd(*str, FD);
		++prt_amn;
		str_len--;
		++str;
	}
	return (prt_amn);
}

void		put_type_str(va_list argptr, t_arg_par *par, int *prt_amt)
{
	char	*arg;
	int		arg_len;
	char	filler_amt;

	arg = va_arg(argptr, char*);
	if (arg == NULL)
		arg = NULL_PLACEHOLDER;
	arg_len = ft_strlen(arg);
	if ((is_f(par, F_PRECIS) == 1) && (par->precis >= 0)
			&& (par->precis < arg_len))
		arg_len = par->precis;
	filler_amt = par->width - arg_len;
	if (is_f(par, F_JUSTIFY) == 0)
	{
		if (is_f(par, F_ZEROFILL) == 1)
			*prt_amt += put_fillers(filler_amt, '0');
		else
			*prt_amt += put_fillers(filler_amt, ' ');
	}
	*prt_amt += put_str_c_fd(arg, arg_len);
	if (is_f(par, F_JUSTIFY) == 1)
		*prt_amt += put_fillers(filler_amt, ' ');
}
