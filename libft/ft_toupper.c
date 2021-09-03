//
// Created by Mickey Rudge on 5/1/21.
//

#include "libft.h"

int	ft_toupper(int ch)
{
	if (ch >= 97 && ch <= 122)
		ch -= 'a' - 'A';
	return (ch);
}
