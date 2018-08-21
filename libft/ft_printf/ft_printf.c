/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:16:45 by ddryha            #+#    #+#             */
/*   Updated: 2017/12/19 16:16:45 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_null_struct(t_flag *head)
{
	head->data = 0;
	head->zero = 0;
	head->left = 0;
	head->width = 0;
	head->sign = 0;
	head->hash = 0;
	head->space = 0;
	head->list = 0;
	head->point = 0;
	head->precision = 0;
	head->c = '\0';
	head->length = n;
}

static	int		ft_check_str(t_flag *head, const char **str)
{
	int		res;
	char	*mas;

	res = 0;
	if (!(mas = ft_strchr(*str, '%')))
	{
		res = ft_strlen(*str);
		write(head->output, *str, res);
		(*str) += res;
	}
	else
	{
		res = mas - (*str);
		write(head->output, *str, res);
		(*str) += res + 1;
	}
	return (res);
}

static	void	ft_check_length(t_flag *head, const char **str)
{
	while ((LENGTH(*(*str))) && *(*str))
	{
		if (*(*str) == 'l' && *(*str + 1) && *(*str + 1) == 'l')
			head->length = ll;
		else if (*(*str) == 'h' && *(*str + 1) && *(*str + 1) == 'h')
			head->length = head->length < hh ? hh : head->length;
		else
		{
			if (*(*str) == 'l')
				head->length = l;
			else if (*(*str) == 'h')
				head->length = head->length < h ? h : head->length;
			else if (*(*str) == 'z')
				head->length = z;
			else if (*(*str) == 'j')
				head->length = j;
		}
		if (head->length == ll || head->length == hh)
			(*str) += 2;
		else if (head->length)
			(*str)++;
	}
}

static	int		ft_analyse_format(const char *str, va_list ap)
{
	int		count;
	t_flag	head;
	int		j;

	count = 0;
	head.output = 1;
	while (*str)
	{
		ft_null_struct(&head);
		count += ft_check_str(&head, &str);
		ft_check_flags(&head, &str, ap);
		ft_check_length(&head, &str);
		if (*str && ((FIRST_FLAGS(*str)) || (SECOND_FLAGS(*str))))
			ft_check_flags(&head, &str, ap);
		if (*str == 'n')
			head.data = count;
		if ((j = ft_check_type(ap, &head, *str)) == -1)
			return (j);
		count += j;
		if (!(*str))
			return (count);
		head.output = *str == 'e' ? 2 : head.output;
		str++;
	}
	return (count);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;

	va_start(ap, format);
	count = ft_analyse_format(format, ap);
	va_end(ap);
	return (count);
}
