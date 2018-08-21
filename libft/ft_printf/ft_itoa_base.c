/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:18:41 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/10 17:18:41 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa_base(intmax_t n, int base)
{
	char	*temp;
	int		i;
	int		j;

	i = ft_nbr_char(n, base);
	temp = ft_strnew(i);
	temp[i--] = '\0';
	if (n == 0)
		temp[i] = '0';
	if (n < 0)
	{
		n = ABS(n);
		temp[0] = '-';
	}
	while (n)
	{
		if ((j = n % base) < 10)
			temp[i--] = j + '0';
		else
			temp[i--] = j - 10 + 'a';
		n /= base;
	}
	return (temp);
}
