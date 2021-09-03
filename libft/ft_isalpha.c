//
// Created by Mickey Rudge on 5/1/21.
//
// Возвращает кодовый номер символа, если приходит символ, если нет, то
// возвращает 0.

#include "libft.h"

int	ft_isalpha(int ch)
{
	if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
		return (ch);
	return (0);
}
