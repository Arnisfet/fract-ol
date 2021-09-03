#include "../fractol.h"

static int	connect_init(t_connect *connect)
{
	connect->connect = mlx_init();
	if (!(connect->connect))
		return (1);
	connect->mlx_win = mlx_new_window(connect->connect, WD, HG, "fractol");
	if (!(connect->mlx_win))
		return (1);
	connect->img = mlx_new_image(connect->connect, WD, HG);
	if (!(connect->img))
		return (1);
	connect->addr = (int *)mlx_get_data_addr(connect->img,
			&connect->bites_per_px,
			&connect->line_length, &connect->endian);
	if (!(connect->addr))
		return (1);
	return (0);
}

void	ft_malloc_fr(t_frctl *frctl)
{
	frctl->mlx = (t_connect *)malloc(sizeof(t_connect));
	if (!frctl->mlx)
		ft_puterror("error!", frctl);
	frctl->mtrx = (t_mtrx *)malloc(sizeof(t_mtrx));
	if (!frctl->mtrx)
		ft_puterror("error!", frctl);
	frctl->cmplx = (t_cmplx *)malloc(sizeof(t_cmplx));
	if (!frctl->cmplx)
		ft_puterror("error!", frctl);
}

void	ft_put_fr_towin(t_frctl *frctl)
{
	if (frctl->mtrx->flag == 'm')
		mandelbro_dr(frctl);
	else if (frctl->mtrx->flag == 'j')
		julia_dr(frctl);
	else if (frctl->mtrx->flag == 's')
		serpinskiy_dr(frctl);
	else if (frctl->mtrx->flag == 'b')
		burn_dr(frctl);
	else if (frctl->mtrx->flag == 'f')
		frctl_dr(frctl);
}

int	main(int ac, char **argv)
{
	t_frctl	*frctl;

	frctl = NULL;
	if (ac >= 2)
	{
		frctl = (t_frctl *)malloc(sizeof(t_frctl));
		if (!frctl)
			return (0);
		ft_malloc_fr(frctl);
		connect_init(frctl->mlx);
		ft_choose(argv, frctl, ac);
		mlx_put_image_to_window(frctl->mlx->connect, frctl->mlx->mlx_win,
			frctl->mlx->img, 0, 0);
		ft_hook(frctl);
		mlx_loop(frctl->mlx->connect);
	}
	else
		ft_puterror("Choose:\n--->mandelbrot\n--->julia (2, 3)"
			"\n--->serpinskiy\n--->burningship\n--->triple",
			frctl);
	return (0);
}
