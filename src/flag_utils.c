/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:28:15 by cjettie           #+#    #+#             */
/*   Updated: 2021/01/13 12:46:11 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flag_utils.h"

void	set_f(FLAG_STORE *f_store, FLAG_STORE flag, int value)
{
	if (value == 0)
		*f_store = *f_store & (~flag);
	else
		*f_store = *f_store | flag;
}

int	is_f(FLAG_STORE *f_store, FLAG_STORE flag)
{
	if ((*f_store & flag) == 0)
		return (0);
	return (1);
}
