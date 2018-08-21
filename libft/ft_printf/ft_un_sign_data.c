/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_sign_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:03:21 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/29 19:03:22 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int		ft_pointer(va_list ap, t_flag *head, char c, char **temp)
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

static	int		ft_octal(va_list ap, t_flag *head, char c, char **temp)
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

static	int		ft_un_sign_integer(va_list ap, t_flag *head, char c,
	char **temp)
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

int				ft_un_sign_data(va_list ap, t_flag *head, char n, char **temp)
{
	int res;

	if (n == 'u' || n == 'U')
		res = ft_un_sign_integer(ap, head, n, temp);
	else if (n == 'o' || n == 'O')
		res = ft_octal(ap, head, n, temp);
	else
		res = ft_pointer(ap, head, n, temp);
	return (res);
}
