/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 17:22:40 by ddryha            #+#    #+#             */
/*   Updated: 2017/11/02 17:22:41 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*temp;
	int		k;

	k = 0;
	temp = NULL;
	if (s && f)
		temp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (temp)
	{
		while (s[k] != '\0')
		{
			temp[k] = f(s[k]);
			k++;
		}
		temp[k] = '\0';
	}
	return (temp);
}
