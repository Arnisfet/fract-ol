//
// Created by Mickey Rudge on 5/1/21.
//
// Возвращает кодовый номер числа

#include "libft.h"

int	ft_isdigit(int ch)
{
	if (ch >= 48 && ch <= 57)
		return (ch);
	return (0);
}
