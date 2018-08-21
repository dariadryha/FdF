/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:12:34 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/09 14:12:35 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_wchar_len(wchar_t n)
{
	if (n <= 0x7F)
		return (1);
	else if (n <= 0x07FF)
		return (2);
	else if (n <= 0xFFFF)
		return (3);
	else if (n <= 0x10FFFF)
		return (4);
	else
		return (-1);
}
