/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:42:47 by ddryha            #+#    #+#             */
/*   Updated: 2017/11/03 15:42:47 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;

	temp = NULL;
	if (s1 && s2)
		temp = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (temp)
	{
		ft_strcpy(temp, s1);
		ft_strcat(temp, s2);
	}
	return (temp);
}
