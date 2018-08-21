/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:17:58 by ddryha            #+#    #+#             */
/*   Updated: 2018/01/11 19:17:59 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	ft_wputnstr(t_flag *head, wchar_t *result, unsigned int n)
{
	unsigned int	i;
	int				j;

	i = 0;
	while (*result)
	{
		j = ft_wchar_len(*result);
		if (MB_CUR_MAX == 1)
			j = 1;
		i += j;
		if (i <= n)
		{
			if (MB_CUR_MAX == 1)
				write(head->output, &(*result), 1);
			else
				ft_wputchar(head, *result);
		}
		else
			break ;
		result++;
	}
}

static	void	ft_print_wstr_result(t_flag *head, wchar_t *result, char *temp)
{
	if (head->left)
	{
		if (head->precision)
			ft_wputnstr(head, result, head->precision);
		else
		{
			if (head->data)
				ft_wputstr(head, result);
		}
		if (head->width)
			write(head->output, temp, head->width);
	}
	else
	{
		if (head->width)
			write(head->output, temp, head->width);
		if (head->precision)
			ft_wputnstr(head, result, head->precision);
		else
		{
			if (head->data)
				ft_wputstr(head, result);
		}
	}
}

static	int		ft_count_wide_len(wchar_t *str, unsigned int n)
{
	int res;

	if (n)
		res = ft_wstr_n_len(str, n);
	else
		res = ft_wstr_len(str);
	return (res);
}

static	int		ft_wide_error(wchar_t *str)
{
	if (MB_CUR_MAX != 1)
		return (0);
	while (*str)
	{
		if (*str > 255)
			return (-1);
		str++;
	}
	return (0);
}

int				ft_print_wstr(va_list ap, t_flag *head, char **temp)
{
	wchar_t		*str;
	int			res;

	str = va_arg(ap, wchar_t *);
	if ((ft_wide_error(str)))
		return (-1);
	if (!str)
	{
		write(head->output, "(null)", 6);
		return (ft_strlen("(null)"));
	}
	if (!head->precision && head->point)
		res = 0;
	else
	{
		if ((res = ft_count_wide_len(str, head->precision)) == -1)
			return (-1);
	}
	head->data = res;
	ft_mng_flg_char(head, &res, temp);
	ft_print_wstr_result(head, str, *temp);
	return (res);
}
