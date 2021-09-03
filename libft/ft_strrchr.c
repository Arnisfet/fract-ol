//
// Created by vitya on 28.04.2021.
//
//Функция ищет последний входящий байт равный ch, работает как strchr.
#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;

	i = (size_t) ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i--;
	}
	if (str[i] == ch)
		return ((char *)str + i);
	return (NULL);
}
