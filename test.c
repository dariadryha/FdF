#include <math.h>
#include <stdio.h>

#include "libft/includes/libft.h"

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

int		ft_atoi_base(char *str, int base)
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

// static int	convert_and_check_nb(char c, int base)
// {
// 	int		result;

// 	printf("%c\n", c);
// 	if (c >= '0' && c <= '9')
// 		result = c - 48;
// 	else if (c >= 'a' && c <= 'z')
// 		result = c - 97 + 10;
// 	else if (c >= 'A' && c <= 'Z')
// 		result = c - 65 + 10;
// 	else
// 		result = -1;
// 	printf("%d\n", result);
// 	if (result < base && result != -1)
// 		return (result);
// 	else
// 		return (-1);
// }

// static int	length_number(char *str, int base)
// {
// 	int		length;

// 	length = 0;
// 	while (str[length])
// 	{
// 		if (convert_and_check_nb(str[length], base) == -1)
// 			break ;
// 		length++;
// 	}
// 	return (length);
// }

// int			ft_atoi_base(char *nb, int base)
// {
// 	int		result;
// 	int		length;

// 	if (base == 10)
// 		return (ft_atoi(nb));
// 	while (*nb == ' ' || *nb == '\t' || *nb == '\n'
// 			|| *nb == '\v' || *nb == '\r' || *nb == '\f')
// 		nb++;
// 	result = 0;
// 	length = length_number(nb, base) - 1;
// 	printf("%d\n", length);
// 	while (*nb && length >= 0 && convert_and_check_nb(*nb, base) != -1)
// 	{
// 		result += convert_and_check_nb(*nb, base) * pow(base, length);
// 		nb++;
// 		length--;
// 	}
// 	return (result);
// }

int main(void)
{
	int j = ft_atoi_base("   ffaa", 16);
	printf("%x\n", 0);
	return (0);
}