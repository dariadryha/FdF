/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:13:30 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/11 19:13:30 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	ft_right_str_justify(t_flag *head, char *result, char *temp)
{
	if (head->width)
		write(head->output, temp, head->width);
	if (head->precision)
		write(head->output, result, head->precision);
	else
	{
		if (head->data)
			write(head->output, result, head->data);
	}
}

static	void	ft_left_str_justify(t_flag *head, char *result, char *temp)
{
	if (head->precision)
		write(head->output, result, head->precision);
	else
	{
		if (head->data)
			write(head->output, result, head->data);
	}
	if (head->width)
		write(head->output, temp, head->width);
}

static	void	ft_print_str_result(t_flag *head, char *result, char *temp)
{
	if (head->left)
		ft_left_str_justify(head, result, temp);
	else
		ft_right_str_justify(head, result, temp);
}

int				ft_print_str(va_list ap, t_flag *head, char **temp)
{
	char	*str;
	int		res;

	if (head->length == l)
		return (ft_print_wstr(ap, head, temp));
	str = va_arg(ap, char *);
	if (!str)
		res = ft_strlen("(null)");
	if (!head->precision && head->point)
		res = 0;
	else if (str)
		res = ft_strlen(str);
	head->data = res;
	ft_mng_flg_char(head, &res, temp);
	if (str)
		ft_print_str_result(head, str, *temp);
	else
		ft_print_str_result(head, "(null)", *temp);
	return (res);
}
