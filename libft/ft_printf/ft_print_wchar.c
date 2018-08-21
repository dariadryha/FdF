/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:09:27 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/15 13:09:27 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	ft_print_wchar_result(t_flag *head, wchar_t n, char *temp)
{
	if (head->left)
	{
		ft_wputchar(head, n);
		if (head->width)
			write(head->output, temp, head->width);
	}
	else
	{
		if (head->width)
			write(head->output, temp, head->width);
		ft_wputchar(head, n);
	}
}

int				ft_print_wchar(va_list ap, t_flag *head, char c, char **temp)
{
	wchar_t		n;
	int			res;

	if (MB_CUR_MAX == 1)
		return (ft_print_char(ap, head, c, temp));
	if ((n = (wchar_t)va_arg(ap, wint_t)) == -1)
		return (-1);
	if ((res = ft_wchar_len(n)) == -1)
		return (-1);
	ft_mng_flg_char(head, &res, temp);
	ft_print_wchar_result(head, n, *temp);
	return (res);
}
