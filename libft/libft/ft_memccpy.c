/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:28:54 by ddryha            #+#    #+#             */
/*   Updated: 2017/10/26 17:28:55 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t k;

	k = 0;
	while (k < n)
	{
		((unsigned char *)dst)[k] = ((unsigned char *)src)[k];
		if (((unsigned char *)src)[k] == (unsigned char)c)
			return (dst + k + 1);
		k++;
	}
	return (NULL);
}
