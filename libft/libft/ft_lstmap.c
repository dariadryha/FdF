/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:33:44 by ddryha            #+#    #+#             */
/*   Updated: 2017/11/13 15:33:44 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_del_lst(t_list *alst)
{
	t_list *blst;

	while (alst)
	{
		blst = alst->next;
		free(alst);
		alst = blst;
	}
	alst = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *temp;
	t_list *head;
	t_list *new;

	if (!lst || !f)
		return (NULL);
	if (!(temp = f(lst)))
		return (NULL);
	new = ft_lstnew(temp->content, temp->content_size);
	head = new;
	lst = lst->next;
	while (lst)
	{
		if (!(temp = f(lst)))
		{
			ft_del_lst(head);
			return (NULL);
		}
		new->next = ft_lstnew(temp->content, temp->content_size);
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
