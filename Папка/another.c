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

int	ft_choose(char **argv, t_frctl *frctl, int ac)
{
	if (ft_strcmp("julia", argv[1]) == 0 && ac == 2)
	{
		frctl->mtrx->cre = -0.49;
		frctl->mtrx->cim = 0.57;
		julia(frctl);
	}
	else if (ft_strcmp("mandelbrot", argv[1]) == 0)
		mandelbrot(frctl);
	else if (ft_strcmp("serpinskiy", argv[1]) == 0)
		serpinskiy(frctl);
	else if (ft_strcmp("burningship", argv[1]) == 0)
		burning_ship(frctl);
	else if (ft_strcmp("triple", argv[1]) == 0)
		my_frctl(frctl);
	else if (ac == 3)
		choose_julia(frctl, argv);
	else
		ft_puterror("Choose:\n--->mandelbrot\n--->julia (2, 3)"
			"\n--->serpinskiy\n--->burningship\n--->triple",
			frctl);
	return (0);
}

int	choose_julia(t_frctl *frctl, char **argv)
{
	if (ft_strcmp("2", argv[2]) == 0)
	{
		frctl->mtrx->cre = -1.2;
		frctl->mtrx->cim = -0.27;
		julia(frctl);
	}
	else if (ft_strcmp("3", argv[2]) == 0)
	{
		frctl->mtrx->cre = -1.6;
		frctl->mtrx->cim = -0.27;
		julia(frctl);
	}
	else
		ft_puterror("Choose:\n--->julia \n--->julia 2\n--->julia 3",
			frctl);
	return (0);
}
