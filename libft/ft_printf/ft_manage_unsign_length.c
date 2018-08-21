/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_unsign_length.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:02:55 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/15 13:02:56 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

uintmax_t	ft_manage_unsign_length(t_flag *head, va_list ap)
{
	uintmax_t n;

	n = va_arg(ap, uintmax_t);
	if (head->length == hh)
		return ((unsigned char)n);
	else if (head->length == h)
		return ((unsigned short int)n);
	else if (head->length == l)
		return ((unsigned long int)n);
	else if (head->length == ll)
		return ((unsigned long long int)n);
	else if (head->length == j)
		return (n);
	else if (head->length == z)
		return ((size_t)n);
	else
		return ((unsigned int)n);
}
