/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:54:58 by ddryha            #+#    #+#             */
/*   Updated: 2017/11/06 11:54:58 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	begin(char const *s)
{
	int k;

	k = 0;
	while ((s[k] == '\n' || s[k] == '\t' || s[k] == ' '))
		k++;
	return (k);
}

static	int	end(char const *s)
{
	int t;

	t = ft_strlen(s);
	while ((s[t - 1] == '\n' || s[t - 1] == '\t' || s[t - 1] == ' ') &&
		(t - 1) >= 0)
		t--;
	return (t);
}

char		*ft_strtrim(char const *s)
{
	char	*temp;
	int		k;
	int		t;
	int		p;

	p = 0;
	k = 0;
	temp = NULL;
	if (s)
	{
		t = end(s);
		if (t)
			k = begin(s);
		temp = (char *)malloc(sizeof(char) * (t - k + 1));
	}
	if (temp)
	{
		while (k < t)
			temp[p++] = s[k++];
		temp[p] = '\0';
	}
	return (temp);
}
