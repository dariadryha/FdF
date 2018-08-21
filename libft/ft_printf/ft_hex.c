/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:34:59 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/11 19:35:00 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	ft_upper_hex(char **temp)
{
	int i;

	i = 0;
	while ((*temp)[i])
	{
		(*temp)[i] = ft_toupper((*temp)[i]);
		i++;
	}
}

int				ft_hex(va_list ap, t_flag *head, char c, char **temp)
{
	char		*result;
	uintmax_t	n;
	int			res;

	n = ft_manage_unsign_length(head, ap);
	res = ft_un_nbr_char(n, 16);
	head->data = res;
	ft_un_flags(head, c);
	ft_manage_un_flags(head, &res, temp, n);
	result = ft_un_itoa_base(n, 16);
	if (c == 'X')
		ft_upper_hex(&result);
	ft_print_result(head, &res, *temp, result);
	return (res);
}
