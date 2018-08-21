/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_mas_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:24:25 by ddryha            #+#    #+#             */
/*   Updated: 2017/11/15 12:24:26 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_mem_mas_num(int i, int j)
{
	int **temp;
	int g;

	g = 0;
	temp = NULL;
	if (i && j)
		temp = (int **)malloc(sizeof(int *) * i);
	if (!temp)
		return (NULL);
	while (g < i)
	{
		if (!(temp[g] = (int *)malloc(sizeof(int) * j)))
			return (NULL);
		ft_bzero(temp[g], j * sizeof(int));
		g++;
	}
	return (temp);
}
