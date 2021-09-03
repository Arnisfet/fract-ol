//
// Created by vitya on 02.05.2021.
//
// Функция сравнивает н байт строки s1 со строкой s2. Предполагается что обе
// строки имеют одинаковое количество байтов.
//
// return: 0 - если 2 строки идентичны, другой результат в случае, если
// строки не равны.
#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)arr1;
	p2 = (unsigned char *)arr2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}
