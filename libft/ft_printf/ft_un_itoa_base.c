/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_itoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:34:04 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/12 13:34:04 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_un_itoa_base(uintmax_t n, int base)
{
	char	*temp;
	int		i;
	int		j;

	i = ft_un_nbr_char(n, base);
	temp = ft_strnew(i);
	temp[i--] = '\0';
	if (n == 0)
		temp[i] = '0';
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
