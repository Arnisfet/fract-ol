//
// Created by Mickey Rudge on 4/30/21.
//
// Функция конвертирует чар в инт, и возвращает полученное число.

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*p;
	int		x;
	int		minus;

	x = 0;
	minus = 1;
	p = (char *)str;
	while (*p == '\t' || *p == '\n' || *p == '\v' || *p == '\f' || *p == '\r'
		|| *p == ' ')
		p++;
	if (*p == 45 || *p == 43)
	{
		if (*p == 45)
			minus *= -1;
		p++;
	}
	while (*p >= '0' && *p <= '9')
	{
		x = x * 10 + (*p - '0');
		p++;
	}
	return (x * minus);
}
