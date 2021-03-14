/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:28:50 by cjettie           #+#    #+#             */
/*   Updated: 2020/12/08 19:29:13 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

# define SEPARATOR_FT 	printf ( "<-printf_ft: %d<%d\n", status, test_counter++);
# define SEPARATOR 	printf ( "<-printf: %d\n", status);

//# define SHOW_CHAR
//# define SHOW_DEX
//#define SHOW_UNS
//# define SHOW_HEX
//# define SHOW_PTR
//# define SHOW_ZERO
//# define SHOW_STRING
//# define SHOW_SIZE
# define SHOW_FLOAT

int		main()
{
	int 	status;
	int 	test_counter;
	long long int lli_min;
	long long int lli_max;


	test_counter = 0;
	lli_min = - 9223372036854775478;
	lli_max = 9223372036854775478;
#ifdef SHOW_CHAR
	status = ft_printf("%5c", 'a');
	SEPARATOR_FT
	status = printf ("%5c", 'a');
	SEPARATOR

	status = ft_printf("%05c", 'a');
	SEPARATOR_FT
	status = printf ("%05c", 'a');
	SEPARATOR

	status = ft_printf("%-05c", 'a');
	SEPARATOR_FT
	status = printf ("%-05c", 'a');
	SEPARATOR

	status = ft_printf("%5c", 'a');
	SEPARATOR_FT
	status = printf ("%5c", 'a');
	SEPARATOR
#endif
#ifdef SHOW_DEX
	status = ft_printf("%d", 7);
	SEPARATOR_FT
	status = printf ("%d", 7);
	SEPARATOR

	status = ft_printf("%d", 10);
	SEPARATOR_FT
	status = printf ("%d", 10);
	SEPARATOR

	status = ft_printf("%d", -7);
	SEPARATOR_FT
	status = printf ("%d", -7);
	SEPARATOR

	status = ft_printf("%+d", 7);
	SEPARATOR_FT
	status = printf ("%+d", 7);
	SEPARATOR

	status = ft_printf("%+d", -7);
	SEPARATOR_FT
	status = printf ("%+d", -7);
	SEPARATOR

	status = ft_printf("%5d", 7);
	SEPARATOR_FT
	status = printf ("%5d", 7);
	SEPARATOR

	status = ft_printf("%5d", -7);
	SEPARATOR_FT
	status = printf ("%5d", -7);
	SEPARATOR

	status = ft_printf("%05d", 7);
	SEPARATOR_FT
	status = printf ("%05d", 7);
	SEPARATOR

	status = ft_printf("%05d", -7);
	SEPARATOR_FT
	status = printf ("%05d", -7);
	SEPARATOR

	status = ft_printf("%+05d", 7);
	SEPARATOR_FT
	status = printf ("%+05d", 7);
	SEPARATOR

	status = ft_printf("%+05d", -7);
	SEPARATOR_FT
	status = printf ("%+05d", -7);
	SEPARATOR

	status = ft_printf("% 05d", 7);
	SEPARATOR_FT
	status = printf ("% 05d", 7);
	SEPARATOR

	status = ft_printf("% 05d", -7);
	SEPARATOR_FT
	status = printf ("% 05d", -7);
	SEPARATOR


	status = ft_printf("%-05d", 7);
	SEPARATOR_FT
	status = printf ("%-05d", 7);
	SEPARATOR

	status = ft_printf("%-05d", -7);
	SEPARATOR_FT
	status = printf ("%-05d", -7);
	SEPARATOR

	status = ft_printf("%-5d", 7);
	SEPARATOR_FT
	status = printf ("%-5d", 7);
	SEPARATOR

	status = ft_printf("%-05d", -7);
	SEPARATOR_FT
	status = printf ("%-05d", -7);
	SEPARATOR

	status = ft_printf("%-+5d", 7);
	SEPARATOR_FT
	status = printf ("%-+5d", 7);
	SEPARATOR

	status = ft_printf("%-+05d", -7);
	SEPARATOR_FT
	status = printf ("%-+05d", -7);
	SEPARATOR

	status = ft_printf("%-5.1d", 7);
	SEPARATOR_FT
	status = printf ("%-5.1d", 7);
	SEPARATOR

	status = ft_printf("%-07.4d", -7);
	SEPARATOR_FT
	status = printf ("%-07.4d", -7);
	SEPARATOR

	status = ft_printf("%07.4d", -7);
	SEPARATOR_FT
	status = printf ("%07.4d", -7);
	SEPARATOR

	status = ft_printf("%.0d", 0);
	SEPARATOR_FT
	status = printf ("%.0d", 0);
	SEPARATOR
#endif
#ifdef SHOW_UNS
	status = ft_printf("%u", 7);
	SEPARATOR_FT
	status = printf ("%u", 7);
	SEPARATOR

	status = ft_printf("%u", 10);
	SEPARATOR_FT
	status = printf ("%u", 10);
	SEPARATOR

	status = ft_printf("%u", -7);
	SEPARATOR_FT
	status = printf ("%u", -7);
	SEPARATOR

	status = ft_printf("%+u", 7);
	SEPARATOR_FT
	status = printf ("%+u", 7);
	SEPARATOR

	status = ft_printf("%+u", -7);
	SEPARATOR_FT
	status = printf ("%+u", -7);
	SEPARATOR

	status = ft_printf("%5u", 7);
	SEPARATOR_FT
	status = printf ("%5u", 7);
	SEPARATOR

	status = ft_printf("%5u", -7);
	SEPARATOR_FT
	status = printf ("%5u", -7);
	SEPARATOR

	status = ft_printf("%05u", 7);
	SEPARATOR_FT
	status = printf ("%05u", 7);
	SEPARATOR

	status = ft_printf("%05u", -7);
	SEPARATOR_FT
	status = printf ("%05u", -7);
	SEPARATOR

	status = ft_printf("%+05u", 7);
	SEPARATOR_FT
	status = printf ("%+05u", 7);
	SEPARATOR

	status = ft_printf("%+05u", -7);
	SEPARATOR_FT
	status = printf ("%+05u", -7);
	SEPARATOR

	status = ft_printf("% 05u", 7);
	SEPARATOR_FT
	status = printf ("% 05u", 7);
	SEPARATOR

	status = ft_printf("% 05u", -7);
	SEPARATOR_FT
	status = printf ("% 05u", -7);
	SEPARATOR


	status = ft_printf("%-05u", 7);
	SEPARATOR_FT
	status = printf ("%-05u", 7);
	SEPARATOR

	status = ft_printf("%-05u", -7);
	SEPARATOR_FT
	status = printf ("%-05u", -7);
	SEPARATOR

	status = ft_printf("%-5u", 7);
	SEPARATOR_FT
	status = printf ("%-5u", 7);
	SEPARATOR

	status = ft_printf("%-05u", -7);
	SEPARATOR_FT
	status = printf ("%-05u", -7);
	SEPARATOR

	status = ft_printf("%-+5u", 7);
	SEPARATOR_FT
	status = printf ("%-+5u", 7);
	SEPARATOR

	status = ft_printf("%-+05u", -7);
	SEPARATOR_FT
	status = printf ("%-+05u", -7);
	SEPARATOR

	status = ft_printf("%-5.1u", 7);
	SEPARATOR_FT
	status = printf ("%-5.1u", 7);
	SEPARATOR

	status = ft_printf("%-07.4u", -7);
	SEPARATOR_FT
	status = printf ("%-07.4u", -7);
	SEPARATOR

	status = ft_printf("%07.4u", -7);
	SEPARATOR_FT
	status = printf ("%07.4u", -7);
	SEPARATOR

	status = ft_printf("%07.4u", 7);
	SEPARATOR_FT
	status = printf ("%07.4u", 7);
	SEPARATOR

	status = ft_printf("%.0u", 0);
	SEPARATOR_FT
	status = printf ("%.0u", 0);
	SEPARATOR
#endif
#ifdef SHOW_STRING
	status = ft_printf("%15s", "lolstring");
	SEPARATOR_FT
	status = printf ("%15s", "lolstring");
	SEPARATOR

	status = ft_printf("%-15s", "lolstring");
	SEPARATOR_FT
	status = printf ("%-15s", "lolstring");
	SEPARATOR

	status = ft_printf("%-3s", "lolstring");
	SEPARATOR_FT
	status = printf ("%-3s", "lolstring");
	SEPARATOR

	status = ft_printf("%-3s", NULL);
	SEPARATOR_FT
	status = printf ("%-3s", (char*)NULL);
	SEPARATOR
#endif
#ifdef SHOW_HEX
	status = ft_printf("%-5x", 16);
	SEPARATOR_FT
	status = printf ("%-5x", 16);
	SEPARATOR


	status = ft_printf("%010X", -45342555);
	SEPARATOR_FT
	status = printf ("%010X", -45342555);
	SEPARATOR

	status = ft_printf("%20x", 16);
	SEPARATOR_FT
	status = printf ("%20x", 16);
	SEPARATOR


	status = ft_printf("%20.15X", -45342555);
	SEPARATOR_FT
	status = printf ("%20.15X", -45342555);
	SEPARATOR

	status = ft_printf("%-+20.15X", -45342555);
	SEPARATOR_FT
	status = printf ("%-+20.15X", -45342555);
	SEPARATOR
#endif
#ifdef SHOW_PTR
	status = ft_printf("%20p", NULL);
	SEPARATOR_FT
	status = printf ("%20p", NULL);
	SEPARATOR

	status = ft_printf("%+020p", &status);
	SEPARATOR_FT
	status = printf ("%+020p", &status);
	SEPARATOR

	status = ft_printf("%+020.p", &status);
	SEPARATOR_FT
	status = printf ("%+020.p", &status);
	SEPARATOR

	status = ft_printf("%+020.15p", &status);
	SEPARATOR_FT
	status = printf ("%+020.15p", &status);
	SEPARATOR
#endif
#ifdef SHOW_ZERO
	status = ft_printf("%20p", NULL);
	SEPARATOR_FT
	status = printf ("%20p", NULL);
	SEPARATOR

	status = ft_printf("%20.p", NULL);
	SEPARATOR_FT
	status = printf ("%20.p", NULL);
	SEPARATOR

	status = ft_printf("%20d", 0);
	SEPARATOR_FT
	status = printf ("%20d", 0);
	SEPARATOR

	status = ft_printf("%20.d", 0);
	SEPARATOR_FT
	status = printf ("%20.d", 0);
	SEPARATOR

	status = ft_printf("%20u", 0);
	SEPARATOR_FT
	status = printf ("%20u", 0);
	SEPARATOR

	status = ft_printf("%20.u", 0);
	SEPARATOR_FT
	status = printf ("%20.u", 0);
	SEPARATOR
#endif
#ifdef SHOW_SIZE
	status = ft_printf("%20lld", lli_min);
	SEPARATOR_FT
	status = printf ("%20lld", lli_min);
	SEPARATOR

	status = ft_printf("%20lld", lli_max);
	SEPARATOR_FT
	status = printf ("%20lld", lli_max);
	SEPARATOR

	status = ft_printf("%20ld", lli_min);
	SEPARATOR_FT
	status = printf ("%20ld", lli_min);
	SEPARATOR

	status = ft_printf("%20ld", lli_max);
	SEPARATOR_FT
	status = printf ("%20ld", lli_max);
	SEPARATOR

	status = ft_printf("%20hd", lli_min);
	SEPARATOR_FT
	status = printf ("%20hd", lli_min);
	SEPARATOR

	status = ft_printf("%20hd", lli_max);
	SEPARATOR_FT
	status = printf ("%20hd", lli_max);
	SEPARATOR

	status = ft_printf("%20hhd", lli_min);
	SEPARATOR_FT
	status = printf ("%20hhd", lli_min);
	SEPARATOR

	status = ft_printf("%20hhd", lli_max);
	SEPARATOR_FT
	status = printf ("%20hhd", lli_max);
	SEPARATOR
#endif
#ifdef SHOW_FLOAT
	status = ft_printf("%40.40f", 1e-1);
	SEPARATOR_FT
	status = printf ("%40.40f", 1e-1);
	SEPARATOR

	status = ft_printf("%20.20f", 1234567e14);
	SEPARATOR_FT
	status = printf ("%20.20f", 1234567e14);
	SEPARATOR


	status = ft_printf("%20.20f", 1234567e15);
	SEPARATOR_FT
	status = printf ("%20.20f", 1234567e15);
	SEPARATOR

	status = ft_printf("%20.20f", 1234567e-15);
	SEPARATOR_FT
	status = printf ("%20.20f", 1234567e-15);
	SEPARATOR

	status = ft_printf("%20f", 1234567e-16);
	SEPARATOR_FT
	status = printf ("%20f", 1234567e-16);
	SEPARATOR

	status = ft_printf("%20f", lli_max);
	SEPARATOR_FT
	status = printf ("%20f", lli_max);
	SEPARATOR

	status = ft_printf("%20f", lli_min);
	SEPARATOR_FT
	status = printf ("%20f", lli_min);
	SEPARATOR

	status = ft_printf("%20f", lli_max);
	SEPARATOR_FT
	status = printf ("%20f", lli_max);
	SEPARATOR

	status = ft_printf("%20f", lli_min);
	SEPARATOR_FT
	status = printf ("%20f", lli_min);
	SEPARATOR

	status = ft_printf("%20f", lli_max);
	SEPARATOR_FT
	status = printf ("%20f", lli_max);
	SEPARATOR
#endif


	return (0);
}
