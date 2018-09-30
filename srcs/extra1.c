#include "../fdf.h"

void		del_content(void *content, size_t size)
{
	free(content);
	size = 0;
}

static	int	ft_check_value(char c, int base)
{
	if (c >= 'A' && c <= 'F')
		c -= 55;
	else if (c >= 'a' && c <= 'f')
		c -= 87;
	else if (c >= '0' && c <= '9')
		c -= '0';
	else
		c = -1;
	if (c < base && c != -1)
		return (c);
	else
		return (-1);

}

static	int	ft_count_power(char *str, int base)
{
	int power;

	power = 0;
	while (str[power])
	{
		if (ft_check_value(str[power], base) == -1)
			break ;
		power++;
	}
	return (power);
}

int			ft_atoi_base(char *str, int base)
{
	int		res;
	int		power;
	char	temp;

	if (base == 10)
		return (ft_atoi(str));
	res = 0;
	while ((*str == ' ' || *str == '\t' || *str == '\v') ||
		(*str == '\n' || *str == '\r' || *str == '\f'))
		str++;
	if (*str && *str == '0' && *(str + 1) && *(str + 1) == 'x')
		str += 2;
	power = ft_count_power(str, base) - 1;
	while (*str)
	{
		if ((temp = ft_check_value(*str, base)) == -1)
			break ;
		res += temp * pow(base, power);
		str++;
		power--;
	}
	return (res);
}
