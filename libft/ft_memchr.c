//
// Created by Mickey Rudge on 4/25/21.
//
// Функция находит первое вхождение в памяти знака с.
//
//return: Возвращает указатель на на байт, или нулл, если с не встретился в
// первых н байтах.
#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)arr;
	while (n-- != 0)
	{
		if (*p == (unsigned char) c)
			return (p);
		p++;
	}
	return (NULL);
}
