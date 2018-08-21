/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_result.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:30:25 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/17 11:30:26 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_char_result(t_flag *head, char n, char *temp)
{
	if (head->left)
	{
		write(head->output, &n, 1);
		if (head->width)
			write(head->output, temp, head->width);
	}
	else
	{
		if (head->width)
			write(head->output, temp, head->width);
		write(head->output, &n, 1);
	}
}
