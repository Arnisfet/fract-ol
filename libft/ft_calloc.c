//
// Created by vitya on 02.05.2021.
//
// Функция возващает указатель на блок памяти размером нам элементов размера
// сайз
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	arr = malloc(size * num);
	if (!arr)
		return (NULL);
	while (i < (num * size))
	{
		arr[i] = '\0';
		i++;
	}
	return ((void *) arr);
}
