/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:33:51 by ddryha            #+#    #+#             */
/*   Updated: 2017/12/15 15:34:14 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ABS(x) ((x < 0) ? -(x) : (x))
# define FIRST_FLAGS(x) ((x == '0' || x == '+' || x == '-' || x == ' ') ? 1 : 0)
# define SECOND_FLAGS(x) ((x == '#' || x == '.' || x == '*') ? 1 : 0)
# define LENGTH(x) ((x == 'h' || x == 'l' || x == 'z' || x == 'j') ? 1 : 0)

# define RED "\033[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define BWHITE "\033[47m"
# define UNDERLINE "\033[4m"
# define RESET "\033[0m"

# include "libft.h"
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>

typedef struct		s_flag
{
	int				width;
	unsigned int	zero;
	unsigned int	left;
	unsigned int	sign;
	unsigned int	hash;
	unsigned int	space;
	unsigned int	list;
	unsigned int	point;
	unsigned int	output;
	int				data;
	int				precision;
	char			c;
	enum {
		n,
		hh,
		h,
		ll,
		l,
		z,
		j
	}				length;
}					t_flag;

int					ft_printf(const char *format, ...);
void				ft_wputchar(t_flag *head, unsigned int n);
int					ft_wchar_len(wchar_t n);
void				ft_wputstr(t_flag *head, wchar_t *str);
int					ft_wstr_len(wchar_t *str);
int					ft_check_type(va_list ap, t_flag *head, char n);
char				*ft_un_itoa_base(uintmax_t n, int base);
char				*ft_itoa_base(intmax_t n, int base);
int					ft_nbr_char(intmax_t n, unsigned int base);
int					ft_un_nbr_char(uintmax_t n, unsigned int base);
void				ft_check_flags(t_flag *head, const char **str, va_list ap);
void				ft_manage_flags(t_flag *head, int *res, char **temp,
	intmax_t n);
void				ft_print_result(t_flag *head, int *res, char *temp,
	char *result);
void				ft_print_spec_format(t_flag *head);
int					ft_print_wstr(va_list ap, t_flag *head, char **temp);
int					ft_print_str(va_list ap, t_flag *head, char **temp);
void				ft_mng_flg_char(t_flag *head, int *res, char **temp);
int					ft_print_char(va_list ap, t_flag *head, char c,
	char **temp);
int					ft_print_wchar(va_list ap, t_flag *head, char c,
	char **temp);
int					ft_hex(va_list ap, t_flag *head, char c, char **temp);
int					ft_sign_integer(va_list ap, t_flag *head, char c,
	char **temp);
void				ft_un_flags(t_flag *head, char c);
intmax_t			ft_manage_sign_length(t_flag *head, va_list ap);
uintmax_t			ft_manage_unsign_length(t_flag *head, va_list ap);
void				ft_manage_un_flags(t_flag *head, int *res, char **temp,
	uintmax_t n);
int					ft_print_percent_result(t_flag *head, char c, char **temp);
void				ft_print_char_result(t_flag *head, char n, char *temp);
int					ft_wstr_n_len(wchar_t *result, unsigned int n);
int					ft_float(va_list ap, t_flag *head, char **temp);
int					ft_un_sign_data(va_list ap, t_flag *head, char n,
	char **temp);

#endif
