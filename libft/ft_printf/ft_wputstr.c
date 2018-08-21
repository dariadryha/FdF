/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:09:29 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/09 14:09:33 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_wputstr(t_flag *head, wchar_t *str)
{
	while (*str)
	{
		if (MB_CUR_MAX == 1)
			write(head->output, &(*str), 1);
		else
			ft_wputchar(head, *str);
		str++;
	}
}
