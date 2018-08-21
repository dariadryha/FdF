/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:21:03 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/11 19:21:04 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_char(va_list ap, t_flag *head, char c, char **temp)
{
	int n;
	int	res;

	if (head->length == l)
		return (ft_print_wchar(ap, head, c, temp));
	n = va_arg(ap, int);
	if (n > 255 && c == 'C')
		return (-1);
	res = 1;
	ft_mng_flg_char(head, &res, temp);
	ft_print_char_result(head, n, *temp);
	return (res);
}
