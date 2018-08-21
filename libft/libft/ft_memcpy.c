/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:28:13 by ddryha            #+#    #+#             */
/*   Updated: 2017/10/26 16:28:13 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			k;

	k = 0;
	if (dst == src)
		return (NULL);
	while (k < n)
	{
		((char *)dst)[k] = ((const char *)src)[k];
		k++;
	}
	return (dst);
}
