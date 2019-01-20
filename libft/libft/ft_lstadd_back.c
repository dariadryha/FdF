/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 10:52:59 by ddryha            #+#    #+#             */
/*   Updated: 2019/01/20 10:53:03 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list *alst, t_list *new)
{
	t_list *temp;

	if (!new || !alst)
		return ;
	temp = alst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
