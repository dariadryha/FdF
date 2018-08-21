/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_n_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:55:55 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/22 12:55:56 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_wstr_n_len(wchar_t *result, unsigned int n)
{
	unsigned int	i;
	int				j;

	i = 0;
	while (*result)
	{
		if ((j = ft_wchar_len(*result)) == -1)
			return (-1);
		if (MB_CUR_MAX == 1)
			j = 1;
		if ((i + j) <= n)
			i += j;
		else
			return (i);
		result++;
	}
	return (i);
}
