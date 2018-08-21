/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mng_flg_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:24:22 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/11 19:24:22 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_mng_flg_char(t_flag *head, int *res, char **temp)
{
	if (head->precision > *res)
	{
		if (!(head->precision = *res))
			head->point = 0;
	}
	*res = head->precision ? head->precision : *res;
	head->zero = head->left ? 0 : head->zero;
	head->zero = head->zero ? '0' : ' ';
	head->width = head->width > *res ? (head->width - *res) : 0;
	*temp = ft_strnew(head->width);
	*temp = ft_memset(*temp, head->zero, head->width);
	(*res) += head->width;
}
