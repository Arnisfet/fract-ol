//
// Created by Mickey Rudge on 4/25/21.
//
// Функция коприует н байт из src в dst. Строки могут перекрываться,
// переркрытия должны обрабатываться
//  return: всегда возвращает значение дест

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (src < dst)
	{
		while (n--)
			*(d + n) = *(s + n);
		return (dst);
	}
	while (n--)
		*d++ = *s++;
	return (dst);
}
