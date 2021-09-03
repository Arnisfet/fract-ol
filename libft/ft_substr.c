//
// Created by vitya on 05.05.2021.
//
// Функция вырезает подстроку из строки s и копирует ее в новый массив
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*arr;
	size_t	i;

	len_s = ft_strlen(s);
	i = 0;
	if (!s || len <= 0 || start >= len_s)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = s[start];
		i++;
		start++;
	}
	arr[i] = '\0';
	return (arr);
}
