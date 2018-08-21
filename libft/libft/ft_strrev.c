/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:15:13 by ddryha            #+#    #+#             */
/*   Updated: 2017/11/15 12:15:14 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *temp)
{
	char	t;
	int		m;
	int		x;

	x = 0;
	if (!temp)
		return ;
	m = ft_strlen(temp) - 1;
	while (x < m)
	{
		t = temp[m];
		temp[m--] = temp[x];
		temp[x++] = t;
	}
}
