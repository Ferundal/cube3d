/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr_all_signed_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:09:07 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/21 16:21:56 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			sign_int_nbr_amt_base(long long int nbr, int base)
{
	int		nbr_len;

	nbr_len = 0;
	while (nbr != 0)
	{
		++nbr_len;
		nbr = nbr / base;
	}
	return (nbr_len);
}

static int	put_sign_int_nbr_base_p(long long int nbr,
									int base_l, char *base, int fd)
{
	int		print_amt;

	print_amt = 0;
	if (nbr > base_l - 1)
	{
		print_amt += put_sign_int_nbr_base_p(nbr / base_l, base_l, base, fd);
		print_amt += ft_put_char_c_fd(*(base + (nbr % base_l)), fd);
	}
	else
		print_amt += ft_put_char_c_fd(*(base + nbr), fd);
	return (print_amt);
}

int			put_sign_int_nbr_base(long long int nbr,
									int base_l, char *base, int fd)
{
	int		print_amt;

	print_amt = 0;
	if (nbr < 0)
		if (nbr < -(base_l - 1))
		{
			print_amt += put_sign_int_nbr_base_p(-(nbr / base_l),
					base_l, base, fd);
			print_amt += ft_put_char_c_fd(*(base + (-(nbr % base_l))), fd);
		}
		else
			print_amt += ft_put_char_c_fd(*(base + (-nbr)), fd);
	else
		print_amt += put_sign_int_nbr_base_p(nbr, base_l, base, fd);
	return (print_amt);
}

int			put_sign_int_nbr_base_prc(long long int nbr,
										t_arg_par *par, char *base, int fd)
{
	int		base_l;
	int		print_amt;

	print_amt = 0;
	base_l = ft_strlen(base);
	print_amt += put_fillers(par->precis -
							sign_int_nbr_amt_base(nbr, base_l), '0');
	if (nbr != 0)
		print_amt += put_sign_int_nbr_base(nbr, base_l, base, fd);
	return (print_amt);
}
