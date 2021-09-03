//
// Created by vitya on 28.04.2021.
//
// Сравнивает строку с2 со строкой с1, если строки равны, то возвращает 0, если
// строки не равны, то возвращает интовое число.
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*p1 && *p2 && --n && *p1 == *p2)
	{
		p1++;
		p2++;
	}
	return ((int)(*p1 - *p2));
}
