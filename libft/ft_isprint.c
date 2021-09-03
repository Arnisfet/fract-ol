//
// Created by Mickey Rudge on 5/1/21.
//

#include "libft.h"

int	ft_isprint(int ch)
{
	if (ch >= 32 && ch <= 126)
		return (ch);
	return (0);
}
