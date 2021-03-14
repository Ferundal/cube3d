/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:49:28 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/21 16:32:23 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../ft_printf.h"

# define F_JUSTIFY (1 << 0)
# define F_ZEROFILL (1 << 1)
# define F_SHOW_PLUS (1 << 2)
# define F_SHOW_SPC (1 << 3)
# define F_PRECIS (1 << 4)
# define F_SIZE_H (1 << 5)
# define F_SIZE_HH (1 << 6)
# define F_SIZE_L (1 << 7)
# define F_SIZE_LL (1 << 8)

# define FLAG_STORE int

# define FD 1

typedef struct			s_arg_par
{
	FLAG_STORE			f;
	int					width;
	int					precis;
}						t_arg_par;

typedef struct			s_arg_float
{
	int					sign;
	unsigned long long	mantis;
	int					exp;
}						t_arg_float;

int						put_arg(const char **str,
								va_list argptr, int *print_amt);

int						read_flags (const char **str, t_arg_par *par);
void					set_f (t_arg_par *par, FLAG_STORE flag, char value);
int						is_f (t_arg_par *par, FLAG_STORE flag);

int						read_width (const char **str,
									t_arg_par *par, va_list argptr);
int						read_precis (const char **str,
									t_arg_par *par, va_list argptr);
int						read_size(const char **str, t_arg_par *par);

int						put_if_type(const char **str,
							t_arg_par *par, va_list argptr, int *print_amt);

int						find_prc(t_arg_par *par, int nbr_len);
unsigned long long int	get_uns_arg(t_arg_par *par, va_list argptr);

void					put_type_int(va_list argptr, t_arg_par *par,
									int *print_amt);
int						sign_int_nbr_amt_base(long long int nbr, int base);
int						put_sign_int_nbr_base_prc(long long int nbr,
										t_arg_par *par, char *base, int fd);

void					put_type_uns(va_list argptr,
									t_arg_par *par, int *prt_amt);
int						uns_int_nbr_amt_base(unsigned long long int nbr,
											unsigned long long int base);
int						put_uns_int_nbr_base_prc(unsigned long long int nbr,
											t_arg_par *par, char *base, int fd);

void					put_type_char(va_list argptr, t_arg_par *par,
										int *prt_amt);
void					put_type_char_pct(t_arg_par *par, int *prt_amt);
void					put_type_str(va_list argptr,
									t_arg_par *par, int *prt_amt);
void					put_type_pointer(va_list argptr,
									t_arg_par *par, int *prt_amt);

void					put_type_hex_s(va_list argptr,
									t_arg_par *par, int *prt_amt);
void					put_type_hex_l(va_list argptr,
									t_arg_par *par, int *prt_amt);

void					put_type_float(va_list argptr,
									t_arg_par *par, int *print_amt);
t_arg_float				read_float_to_int (float *arg);

int						ft_put_char_c_fd(char c, int fd);
int						put_fillers(int amt, char filler);
#endif
