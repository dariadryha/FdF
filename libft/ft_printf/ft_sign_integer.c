/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:32:55 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/12 13:32:56 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_sign_integer(va_list ap, t_flag *head, char c, char **temp)
{
	int			res;
	intmax_t	n;

	if (c == 'D')
		head->length = l;
	n = ft_manage_sign_length(head, ap);
	res = ft_nbr_char(n, 10);
	head->data = (n < 0 ? (res - 1) : res);
	ft_manage_flags(head, &res, temp, n);
	n = ABS(n);
	ft_print_result(head, &res, *temp, ft_un_itoa_base(n, 10));
	return (res);
}
