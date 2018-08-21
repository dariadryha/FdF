/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:25:51 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/09 14:25:53 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	ft_save_flags(t_flag *head, char n)
{
	if (n == '+')
		head->sign = 1;
	else if (n == '-')
		head->left = 1;
	else if (n == '0')
		head->zero = 1;
	else if (n == ' ')
		head->space = 1;
	else if (n == '#')
		head->hash = 1;
	else if (n == '*')
		head->list = 1;
	else if (n == '.')
		head->point = 1;
}

static	void	ft_check_list_params(t_flag *head, va_list ap)
{
	int i;

	i = 0;
	if (head->list)
	{
		i = va_arg(ap, int);
		if (head->point)
		{
			head->precision = (i <= 0 ? 0 : i);
			head->point = (i < 0 ? 0 : 1);
		}
		else
		{
			if (i < 0)
			{
				i *= -1;
				head->left = 1;
			}
			head->width = i;
		}
		head->list = 0;
	}
}

void			ft_check_flags(t_flag *head, const char **str, va_list ap)
{
	while ((FIRST_FLAGS(*(*str)) || SECOND_FLAGS(*(*str)) ||
		ft_isdigit(*(*str))) && *(*str) != '%' && *(*str))
	{
		ft_save_flags(head, *(*str));
		if (head->list)
			ft_check_list_params(head, ap);
		if (head->point && *(*str + 1) && (ft_isdigit(*(*str + 1))))
		{
			head->precision = ft_atoi(*str + 1);
			(*str) += ft_un_nbr_char(head->precision, 10);
		}
		if (!head->point && (*(*str) != '0' && ft_isdigit(*(*str))))
		{
			head->width = ft_atoi(*str);
			(*str) += ft_un_nbr_char(head->width, 10) - 1;
		}
		(*str)++;
	}
}
