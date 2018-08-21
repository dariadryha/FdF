/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:08:34 by ddryha            #+#    #+#             */
/*   Updated: 2017/11/06 15:08:35 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_put(char **temp, char const *s, char c)
{
	int x;
	int t;

	x = 0;
	while (*s != '\0')
	{
		t = 0;
		temp[x] = (char *)malloc(sizeof(char) * ft_strlen(s));
		if (!temp[x])
			return (NULL);
		if (*s != c)
		{
			while (*s != c && *s != '\0')
				temp[x][t++] = *s++;
			temp[x][t] = '\0';
			x++;
		}
		if (*s == '\0')
			break ;
		s++;
	}
	temp[x] = NULL;
	return (temp);
}

static	int		ft_number(const char *str, char c)
{
	int n;

	n = 1;
	while (*str != '\0')
	{
		if (*str != c && (*(str + 1) == c || *(str + 1) == '\0'))
			n++;
		str++;
	}
	return (n);
}

static	void	ft_del_strs(char **str)
{
	int k;

	k = 0;
	if (!str || !*str)
		return ;
	while (str[k])
		free(str[k++]);
	free(str);
	str = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**temp;
	int		p;

	temp = NULL;
	p = 0;
	if (s)
		p = ft_number(s, c);
	if (p)
		temp = (char **)malloc(sizeof(char *) * p);
	if (temp)
	{
		if (!(ft_put(temp, s, c)))
			ft_del_strs(temp);
	}
	return (temp);
}
