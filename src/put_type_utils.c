/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:06:55 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/21 16:07:09 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int						find_prc(t_arg_par *par, int nbr_len)
{
	if (par->precis > nbr_len)
		return (par->precis);
	return (nbr_len);
}

unsigned long long int	get_uns_arg(t_arg_par *par, va_list argptr)
{
	if (is_f(par, F_SIZE_LL))
		return (va_arg(argptr, unsigned long long int));
	if (is_f(par, F_SIZE_L))
		return (va_arg(argptr, unsigned long int));
	if (is_f(par, F_SIZE_H))
		return ((unsigned short)va_arg(argptr, unsigned int));
	if (is_f(par, F_SIZE_HH))
		return ((unsigned char)va_arg(argptr, unsigned int));
	return (va_arg(argptr, unsigned int));
}
