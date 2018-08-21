/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 17:24:01 by ddryha            #+#    #+#             */
/*   Updated: 2017/11/02 17:24:02 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			temp[k] = f(k, s[k]);
			k++;
		}
		temp[k] = '\0';
	}
	return (temp);
}
