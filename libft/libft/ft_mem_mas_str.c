/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_mas_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:12:18 by ddryha            #+#    #+#             */
/*   Updated: 2017/11/15 13:12:18 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_mem_mas_str(char *str, char c)
{
	char	**temp;
	int		n;

	n = 0;
	temp = NULL;
	if (str)
		temp = (char **)malloc(sizeof(char *) * ft_numword(str, c));
	if (!temp)
		return (NULL);
	while ((n + 1) < ft_numword(str, c))
	{
		if (!(temp[n] = ft_strnew(ft_strlen(str))))
			return (NULL);
		n++;
	}
	temp[n] = NULL;
	return (temp);
}
