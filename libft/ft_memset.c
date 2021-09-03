//
// Created by vitya on 23.04.2021.
//
// Функция заполняет массив s1,  символом с n раз и возвращает массив s1
#include "libft.h"

void	*ft_memset(void *s1, int c, size_t n)
{
	unsigned char	*p1;
	unsigned char	p2;
	size_t			i;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char)c;
	while (i++ < n)
		*p1++ = p2;
	return (s1);
}
