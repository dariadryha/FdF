/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_result.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:04:27 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/15 17:04:29 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_percent_result(t_flag *head, char c, char **temp)
{
	int res;

	res = 1;
	ft_mng_flg_char(head, &res, temp);
	ft_print_char_result(head, c, *temp);
	return (res);
}
