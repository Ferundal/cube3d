/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:28:49 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/21 16:23:23 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "utils.h"

int		ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		print_amt;

	va_start(argptr, str);
	print_amt = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			++str;
			if (put_arg(&str, argptr, &print_amt) < 0)
			{
				va_end(argptr);
				return (-1);
			}
		}
		else
		{
			write(1, str, 1);
			++print_amt;
		}
		++str;
	}
	va_end(argptr);
	return (print_amt);
}
