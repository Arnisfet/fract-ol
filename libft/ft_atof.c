//
// Created by Mickey Rudge on 9/2/21.
//

#include "libft.h"

double	ft_atof(const char *str)
{
	char	*c;
	double	first_part;
	double	second_part;
	int		len;

	c = (char *)str;
	first_part = (double)ft_atoi(str);
	while (*c && *c != '.')
		c++;
	c++;
	second_part = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len)
	{
		second_part /= 10;
		len--;
	}
	if (first_part > 0)
		return (first_part + second_part);
	return (first_part - second_part);
}
