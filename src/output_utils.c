/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:07:39 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/21 16:22:50 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_put_char_c_fd(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int		put_fillers(int amt, char filler)
{
	int		counter;

	counter = 0;
	while (amt > 0)
	{
		counter += ft_put_char_c_fd(filler, 1);
		--amt;
	}
	return (counter);
}
