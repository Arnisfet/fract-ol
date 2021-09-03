//
// Created by Mickey Rudge on 5/1/21.
//
// Возвращает 1, если число принадлежит кодировки аскии, возвращает 0, если нет.

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
