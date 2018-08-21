/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_un_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:58:17 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/15 12:58:18 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

static	int		ft_len_spec_format(t_flag *head)
{
	if (head->hash)
	{
		if (head->c == 'o' || head->c == 'O')
			return (1);
		else if (head->c == 'x' || head->c == 'X')
			return (2);
	}
	if (head->c == 'p')
		return (2);
	return (0);
}

void			ft_manage_un_flags(t_flag *head, int *res, char **temp,
	uintmax_t n)
{
	int middle;

	if (!n)
	{
		if (head->c != 'o' && head->c != 'O')
			head->hash = 0;
		if (((!head->precision && head->point)) ||
			(head->c == 'o' && head->hash) || (head->c == 'O' && head->hash))
		{
			head->data = 0;
			(*res)--;
		}
	}
	*res += ft_len_spec_format(head);
	middle = (head->c == 'o' || head->c == 'O') ? *res : head->data;
	head->precision = head->precision > middle ? (head->precision - middle) : 0;
	head->zero = (head->left || head->precision) ? 0 : head->zero;
	if (head->zero)
		ft_print_spec_format(head);
	head->zero = (head->zero ? '0' : ' ');
	ft_manage_width(head, res, temp);
}
