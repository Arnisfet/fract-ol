//
// Created by Mickey Rudge on 4/25/21.
//
// Коприует из строки src  в строку dest не более чем n-1 символов и
// устанавливает в конец строки нулевой символ
// Возвращает размер строки по исходному массиву
#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (ft_strlen(src));
	if (!src)
		return (i);
	while (src[i] && i < (n - 1))
	{
		dst[i] = src[i];
		i++;
	}
	if (i < n)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
