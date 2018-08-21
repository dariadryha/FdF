/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_sign_length.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:05:52 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/15 13:05:53 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	ft_manage_sign_length(t_flag *head, va_list ap)
{
	intmax_t n;

	n = va_arg(ap, intmax_t);
	if (head->length == hh)
		return ((char)n);
	else if (head->length == h)
		return ((short int)n);
	else if (head->length == l)
		return ((long int)n);
	else if (head->length == ll)
		return ((long long int)n);
	else if (head->length == j)
		return (n);
	else if (head->length == z)
		return ((size_t)n);
	else
		return ((int)n);
}
