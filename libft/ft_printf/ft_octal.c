/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:37:00 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/11 19:37:00 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_octal(va_list ap, t_flag *head, char c, char **temp)
{
	uintmax_t	n;
	int			res;

	res = 0;
	if (c == 'O')
		head->length = l;
	n = ft_manage_unsign_length(head, ap);
	res = ft_un_nbr_char(n, 8);
	head->data = res;
	ft_un_flags(head, c);
	ft_manage_un_flags(head, &res, temp, n);
	ft_print_result(head, &res, *temp, ft_un_itoa_base(n, 8));
	return (res);
}
