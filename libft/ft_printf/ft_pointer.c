/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:45:22 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/11 19:45:22 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_pointer(va_list ap, t_flag *head, char c, char **temp)
{
	uintmax_t	n;
	int			res;

	res = 0;
	n = (long int)va_arg(ap, void *);
	res = ft_un_nbr_char(n, 16);
	head->data = res;
	ft_un_flags(head, c);
	ft_manage_un_flags(head, &res, temp, n);
	ft_print_result(head, &res, *temp, ft_un_itoa_base(n, 16));
	return (res);
}
