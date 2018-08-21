/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 19:12:47 by ddryha            #+#    #+#             */
/*   Updated: 2017/12/06 19:12:47 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_find_str(t_list **temp, char **line, size_t fd, size_t n)
{
	char	*str;
	int		k;

	k = 0;
	while ((*temp)->content_size != fd)
		*temp = (*temp)->next;
	str = (*temp)->content;
	while (str[k] != '\0')
	{
		if (str[k] == '\n')
		{
			*line = ft_strsub(str, 0, k++);
			str = ft_strcpy(str, str + k);
			return (1);
		}
		k++;
	}
	if (k && !n)
	{
		*line = ft_strsub(str, 0, k);
		ft_bzero(str, k);
		return (1);
	}
	return (0);
}

static	int		ft_write_buff(t_list **head, t_list **new,
	char *buff, size_t fd)
{
	char	*temp;

	if (!(*head))
	{
		*head = ft_lstnew("\0", 5);
		(*head)->content_size = fd;
		*new = *head;
	}
	while ((*new)->content_size != fd && (*new)->next)
		*new = (*new)->next;
	if ((*new)->content_size != fd)
	{
		if (!((*new)->next = ft_lstnew(buff, ft_strlen(buff) + 1)))
			return (0);
		*new = (*new)->next;
		(*new)->content_size = fd;
	}
	else
	{
		temp = ft_strdup((*new)->content);
		free((*new)->content);
		(*new)->content = ft_strjoin(temp, buff);
		free(temp);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	ssize_t			n;
	char			buff[BUFF_SIZE + 1];
	static t_list	*head;
	t_list			*new;

	new = head;
	while (line && (n = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[n] = '\0';
		if (!(ft_write_buff(&head, &new, buff, fd)))
			return (-1);
		if (ft_strchr(buff, '\n'))
			if (ft_find_str(&new, line, fd, n))
				return (1);
	}
	if (!line || !new)
		return (-1);
	if (n == -1)
		return (-1);
	if (ft_find_str(&new, line, fd, n))
		return (1);
	return (0);
}
