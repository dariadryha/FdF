/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:30:10 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/09 14:30:11 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	ft_put_sign(t_flag *head, intmax_t n)
{
	if (n >= 0)
		write(head->output, "+", 1);
	if (n < 0)
		write(head->output, "-", 1);
	head->sign = 0;
}

static	void	ft_manage_width(t_flag *head, int *res, char **temp)
{
	head->width = head->width > *res ? (head->width - *res) : 0;
	if (head->width > head->precision)
		head->width = head->width - head->precision;
	else
		head->width = 0;
	*res += head->width;
	*temp = ft_strnew(head->width);
	*temp = ft_memset(*temp, head->zero, head->width);
}

static	void	ft_manage_sign(t_flag *head, int *res, intmax_t n)
{
	if (head->sign)
	{
		if (head->zero || head->left || !head->width)
			ft_put_sign(head, n);
		else
		{
			if (n < 0)
				head->sign = 45;
			if (n > 0)
				head->sign = 43;
		}
		(*res) += (n >= 0 ? 1 : 0);
	}
	else
	{
		if (head->space && (n >= 0))
			*res += write(head->output, " ", 1);
		if (n < 0)
		{
			if (!head->width || (head->width && head->zero))
				ft_put_sign(head, n);
			else if (!head->zero)
				head->sign = 45;
		}
	}
}

void			ft_manage_flags(t_flag *head, int *res, char **temp, intmax_t n)
{
	if (head->precision && n < 0)
		++head->precision;
	head->precision = head->precision > *res ? (head->precision - *res) : 0;
	head->zero = (head->left || head->point) ? 0 : head->zero;
	ft_manage_sign(head, res, n);
	head->zero = (head->zero ? '0' : ' ');
	if (!n && !head->precision && head->point)
	{
		head->data = 0;
		(*res)--;
	}
	ft_manage_width(head, res, temp);
}
