//
// Created by Mickey Rudge on 5/11/21.
//
// Функция счета слов

#include "libft.h"

size_t	ft_count_words(const char *s, char c)
{
	int		len;
	size_t	j;

	j = 0;
	len = 0;
	while (s[len])
	{
		while (s[len] == c && s[len] != '\0')
			len++;
		if (s[len] != c && s[len])
			j++;
		while (s[len] != c && s[len])
			len++;
	}
	return (j);
}
