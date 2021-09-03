//
// Created by Mickey Rudge on 4/25/21.
//
// Функция копирукт байты из строки срц в строку дест, если встречается
// символ с в строке срц, то копирование останавливается, и возвращается
// указатель на байт. Не заботится о перекрытии массивов.
//
//return: Возвращает указаетель на следующий после с символ или NULL, если с
// не найден в первых н символах
#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
					 size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			count;

	count = 0;
	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	while (count < n)
	{
		if (p2[count] == (unsigned char ) c)
		{
			p1[count] = p2[count];
			count++;
			return ((void *)p1 + count);
		}
		p1[count] = p2[count];
		count++;
	}
	return (NULL);
}
