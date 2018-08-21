/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:01:07 by ddryha            #+#    #+#             */
/*   Updated: 2017/11/01 14:01:07 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			j;

	j = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n)
	{
		while (n--)
		{
			if (str1[j] != str2[j])
				return (str1[j] - str2[j]);
			if (str1[j] == '\0' && str2[j] == '\0')
				return (0);
			j++;
		}
	}
	return (0);
}
