/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:20:15 by ddryha            #+#    #+#             */
/*   Updated: 2017/11/10 13:20:18 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_number_char(int n)
{
	int j;
	int p;

	j = -n;
	p = 1;
	if (n < 0)
		p++;
	while (j / 10)
	{
		p++;
		j = j / 10;
	}
	return (p);
}

static	void	ft_reverse(char *temp)
{
	char	t;
	int		m;
	int		x;

	x = 0;
	m = ft_strlen(temp) - 1;
	while (x < m)
	{
		t = temp[m];
		temp[m--] = temp[x];
		temp[x++] = t;
	}
}

static	void	ft_put(char *temp, int n)
{
	int i;
	int c;

	c = 0;
	if ((i = n) < 0)
		i = -n;
	if (i >= 0 && i <= 9)
		temp[c++] = DIGITS[i];
	else
	{
		while (i)
		{
			temp[c++] = DIGITS[i % 10];
			i = i / 10;
		}
	}
	if (n < 0)
		temp[c++] = '-';
	temp[c] = '\0';
	ft_reverse(temp);
}

char			*ft_itoa(int n)
{
	char	*temp;
	int		k;

	k = ft_number_char(n);
	temp = (char *)malloc(sizeof(char) * (k + 1));
	if (temp)
	{
		if (n == MAX_SIZE)
			temp = ft_strcpy(temp, MAX_STRING);
		else
			ft_put(temp, n);
	}
	return (temp);
}
