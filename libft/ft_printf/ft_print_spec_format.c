/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_spec_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:22:41 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/12 13:22:41 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_spec_format(t_flag *head)
{
	if (head->hash)
	{
		if (head->c == 'o' || head->c == 'O')
			write(head->output, "0", 1);
		else if (head->c == 'x' || head->c == 'p')
			write(head->output, "0x", 2);
		else if (head->c == 'X')
			write(head->output, "0X", 2);
		head->hash = 0;
	}
	if (head->c == 'p')
		write(head->output, "0x", 2);
	head->c = 0;
}
