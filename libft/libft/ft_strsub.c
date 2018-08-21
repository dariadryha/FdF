/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:31:23 by ddryha            #+#    #+#             */
/*   Updated: 2017/11/03 14:31:23 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	k;

	temp = NULL;
	k = 0;
	if (s)
		temp = (char *)malloc(len + 1);
	if (temp && start <= ft_strlen(s))
	{
		while (k < len && s[start])
			temp[k++] = s[start++];
		temp[k] = '\0';
	}
	return (temp);
}
