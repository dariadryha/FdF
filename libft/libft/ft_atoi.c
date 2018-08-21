/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:24:49 by ddryha            #+#    #+#             */
/*   Updated: 2017/10/31 17:24:49 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long int	result;
	int					nb;

	nb = 0;
	result = 0;
	while ((*str == ' ' || *str == '\t' || *str == '\v') ||
		(*str == '\n' || *str == '\r' || *str == '\f'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			nb = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str++ - '0';
		if (result >= 9223372036854775807 && nb == 0)
			return (-1);
		if (result > 9223372036854775807 && nb == 1)
			return (0);
	}
	return (nb ? (int)(-result) : (int)result);
}
