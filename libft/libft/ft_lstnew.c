/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:35:46 by ddryha            #+#    #+#             */
/*   Updated: 2017/11/13 11:35:47 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*temp;

	temp = (t_list *)malloc(sizeof(t_list));
	if (temp)
	{
		if (!content)
		{
			temp->content = NULL;
			temp->content_size = 0;
		}
		else
		{
			temp->content = malloc(content_size);
			if (!temp->content)
			{
				free(temp);
				return (NULL);
			}
			ft_memcpy(temp->content, content, content_size);
			temp->content_size = content_size;
		}
		temp->next = NULL;
	}
	return (temp);
}
