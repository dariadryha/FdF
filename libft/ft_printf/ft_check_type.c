/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:48:39 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/11 19:48:39 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	ft_write_count(va_list ap, t_flag *head)
{
	void *n;

	n = va_arg(ap, void *);
	if (head->length == hh)
		*((signed char *)n) = head->data;
	else if (head->length == h)
		*((short int *)n) = head->data;
	else if (head->length == l)
		*((long *)n) = head->data;
	else if (head->length == ll)
		*((long long *)n) = head->data;
	else if (head->length == j)
		*((intmax_t *)n) = head->data;
	else if (head->length == z)
		*((size_t *)n) = head->data;
	else
		*((int *)n) = head->data;
}

int				ft_check_type(va_list ap, t_flag *head, char n)
{
	char	*temp;
	int		res;

	res = 0;
	temp = NULL;
	if (n == 'd' || n == 'i' || n == 'D')
		res = ft_sign_integer(ap, head, n, &temp);
	else if (n == 'x' || n == 'X')
		res = ft_hex(ap, head, n, &temp);
	else if (n == 'o' || n == 'O' || n == 'u' || n == 'U' || n == 'p')
		res = ft_un_sign_data(ap, head, n, &temp);
	else if (n == 's')
		res = ft_print_str(ap, head, &temp);
	else if (n == 'S')
		res = ft_print_wstr(ap, head, &temp);
	else if (n == 'c')
		res = ft_print_char(ap, head, n, &temp);
	else if (n == 'C')
		res = ft_print_wchar(ap, head, n, &temp);
	else if (n == 'n')
		ft_write_count(ap, head);
	else if (n && n != 'e')
		res = ft_print_percent_result(head, n, &temp);
	free(temp);
	return (res);
}
