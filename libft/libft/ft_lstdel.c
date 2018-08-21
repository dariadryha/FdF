/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:50:26 by ddryha            #+#    #+#             */
/*   Updated: 2017/11/13 14:50:26 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *ptr;

	if (!alst || !*alst || !del)
		return ;
	temp = *alst;
	while (temp)
	{
		ptr = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = ptr;
	}
	*alst = NULL;
}
