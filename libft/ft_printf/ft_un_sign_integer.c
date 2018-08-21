/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_sign_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:43:39 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/11 19:43:39 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_un_sign_integer(va_list ap, t_flag *head, char c, char **temp)
{
	uintmax_t	n;
	int			res;

	if (c == 'U')
		head->length = l;
	n = ft_manage_unsign_length(head, ap);
	res = ft_un_nbr_char(n, 10);
	head->data = res;
	ft_un_flags(head, c);
	ft_manage_un_flags(head, &res, temp, n);
	ft_print_result(head, &res, *temp, ft_un_itoa_base(n, 10));
	return (res);
}
