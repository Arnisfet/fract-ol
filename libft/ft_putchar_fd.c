//
// Created by Mickey Rudge on 5/3/21.
//

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
