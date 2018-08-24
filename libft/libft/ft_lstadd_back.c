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
