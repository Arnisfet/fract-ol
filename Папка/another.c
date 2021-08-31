#include "fractol.h"

void	ft_puterror(char *str, t_frctl *frctl)
{
	if (frctl != NULL)
	{
		if (frctl->cmplx != NULL)
			free(frctl->cmplx);
		if (frctl->mlx != NULL)
			free(frctl->mlx);
		if (frctl->mtrx != NULL)
			free(frctl->mtrx);
		free(frctl);
	}
	ft_putstr_fd(str, 1);
	exit(1);
}

int	ft_choose(char *argv, t_frctl *frctl)
{
	if (ft_strcmp("mandelbrot", argv) == 0)
		mandelbrot(frctl);
	else if (ft_strcmp("julia", argv) == 0)
		julia(frctl);
	else if (ft_strcmp("serpinskiy", argv) == 0)
		serpinskiy(frctl);
	else if (ft_strcmp("burningship", argv) == 0)
		burning_ship(frctl);
	else if (ft_strcmp("my_frctl", argv) == 0)
		my_frctl(frctl);
	else
		ft_puterror("Choose: mandelbrot, julia, serpinskiy, burningship",
			frctl);
	return (0);
}
