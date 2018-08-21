/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:52:44 by ddryha            #+#    #+#             */
/*   Updated: 2017/11/01 11:52:45 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t k;
	size_t t;
	size_t m;

	t = 0;
	k = ft_strlen(dst);
	m = k;
	if (dstsize < k)
		return (dstsize + ft_strlen(src));
	while ((k + 1) < dstsize && src[t] != '\0')
		dst[k++] = src[t++];
	dst[k] = '\0';
	return (m + ft_strlen(src));
}
