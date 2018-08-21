/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:59:37 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/09 13:59:38 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	ft_bit_mask(unsigned char *mas,
	unsigned int n, unsigned int *byte)
{
	if (n <= 0x7F)
		mas[(*byte)++] = n;
	else if (n <= 0x07FF)
	{
		mas[(*byte)++] = 0xC0 | (n >> 6);
		mas[(*byte)++] = 0x80 | (n & 0x3F);
	}
	else if (n <= 0xFFFF)
	{
		mas[(*byte)++] = 0xE0 | (n >> 12);
		mas[(*byte)++] = 0x80 | ((n >> 6) & 0x3F);
		mas[(*byte)++] = 0x80 | (n & 0x3F);
	}
	else if (n <= 0x10FFFF)
	{
		mas[(*byte)++] = 0xF0 | (n >> 18);
		mas[(*byte)++] = 0x80 | ((n >> 12) & 0x3F);
		mas[(*byte)++] = 0x80 | ((n >> 6) & 0x3F);
		mas[(*byte)++] = 0x80 | (n & 0x3F);
	}
}

void			ft_wputchar(t_flag *head, unsigned int n)
{
	unsigned char	mas[4];
	unsigned int	byte;

	byte = 0;
	ft_bit_mask(mas, n, &byte);
	if (byte)
		write(head->output, &mas, byte);
}
