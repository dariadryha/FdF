/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:07:18 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/09 14:07:19 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_wstr_len(wchar_t *str)
{
	int res;
	int j;

	res = 0;
	while (*str)
	{
		if ((j = ft_wchar_len(*str)) == -1)
			return (-1);
		if (MB_CUR_MAX == 1)
			j = 1;
		res += j;
		str++;
	}
	return (res);
}
