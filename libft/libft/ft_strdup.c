/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:43:48 by ddryha            #+#    #+#             */
/*   Updated: 2017/10/30 15:43:49 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;
	int		t;

	t = ft_strlen(s1);
	if ((temp = (char *)malloc(sizeof(char) * t + 1)))
	{
		temp = ft_strncpy(temp, s1, t);
		temp[t] = '\0';
		return (temp);
	}
	return (NULL);
}
