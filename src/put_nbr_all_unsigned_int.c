/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr_all_unsigned_int.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:10:16 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/21 16:21:28 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			uns_int_nbr_amt_base(unsigned long long int nbr,
								unsigned long long int base)
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

int			put_uns_int_nbr_base(unsigned long long int nbr,
								unsigned int base_l, char *base, int fd)
{
	int		print_amt;

	print_amt = 0;
	if (nbr > base_l - 1)
	{
		print_amt += put_uns_int_nbr_base(nbr / base_l, base_l, base, fd);
		print_amt += ft_put_char_c_fd(*(base + (nbr % base_l)), fd);
	}
	else
		print_amt += ft_put_char_c_fd(*(base + nbr), fd);
	return (print_amt);
}

int			put_uns_int_nbr_base_prc(unsigned long long int nbr, t_arg_par *par,
									char *base, int fd)
{
	int		base_l;
	int		print_amt;

	print_amt = 0;
	base_l = ft_strlen(base);
	print_amt += put_fillers(par->precis
			- uns_int_nbr_amt_base(nbr, base_l), '0');
	if (nbr != 0)
		print_amt += put_uns_int_nbr_base(nbr, base_l, base, fd);
	return (print_amt);
}
