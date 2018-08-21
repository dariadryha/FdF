/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:45:20 by ddryha            #+#    #+#             */
/*   Updated: 2017/10/30 12:45:21 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t k;

	k = 0;
	while (k < n)
	{
		if (((unsigned char *)s)[k] == (unsigned char)c)
			return (&((unsigned char *)s)[k]);
		k++;
	}
	return (NULL);
}
