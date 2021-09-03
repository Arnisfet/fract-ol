//
// Created by Mickey Rudge on 5/1/21.
//

#include "libft.h"

int	ft_tolower(int ch)
{
	if (ch >= 65 && ch <= 90)
		ch += 'a' - 'A';
	return (ch);
}
