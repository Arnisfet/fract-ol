//
// Created by vitya on 10.05.2021.
//
// Тот же стрдап с выделением и копированием но не больше н символов

#include "libft.h"

char	*ft_strndup(char const *s, size_t n)
{
	char	*str;
	int		i;

	i = ft_strlen(s);
	str = (char *) malloc(sizeof(char) * n + 1);
	if (!str)
		return (NULL);
	str = ft_mystrncpy(str, s, n);
	return (str);
}
