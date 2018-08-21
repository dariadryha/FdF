/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:59:46 by ddryha            #+#    #+#             */
/*   Updated: 2017/11/01 13:59:47 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*(haystack + i) != '\0' && i < len)
	{
		if (ft_strlen(needle) > (len - i))
			break ;
		if (!ft_strncmp(haystack + i, needle, ft_strlen(needle)))
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
