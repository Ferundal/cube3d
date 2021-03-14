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

#ifndef FLAG_UTILS_H
# define FLAG_UTILS_H

# ifndef FLAG_STORE
#  define FLAG_STORE int
# endif

void	set_f(FLAG_STORE *f_store, FLAG_STORE flag, int value);
int		is_f(FLAG_STORE *f_store, FLAG_STORE flag);

#endif
