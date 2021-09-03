//
// Created by vitya on 28.04.2021.
//
// Стрчр ищет ищет в массиве первый схожий по размеру байт, если находит, то
// возвращает указатель на него, если нет, то возвращает нул.
//
#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char	*p;
	char	i;

	i = (char)ch;
	p = (char *)str;
	while (*p && *p != ch)
		p++;
	if (*p == ch)
		return (p);
	return (NULL);
}
