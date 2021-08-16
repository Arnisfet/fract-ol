
#include "fractol.h"

int get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_cmplx ft_get_real(t_frctl *frctl)
{
	t_cmplx z;

	z.re = ((4 * (double)frctl->mtrx->x / WD - 2));
	z.im = ((-4 * (double)frctl->mtrx->y / HG + 2));
	frctl->cmplx->ca = z.re;
	frctl->cmplx->cb = z.im;
	return (z);
}

t_cmplx calc_fract(t_frctl *frctl, t_cmplx z)
{
	frctl->cmplx->aa = z.re * z.re - z.im * z.im;
	frctl->cmplx->twoab = 2 * z.re * z.im;
	z.re = frctl->cmplx->aa + frctl->cmplx->ca;
	z.im = frctl->cmplx->twoab + frctl->cmplx->cb;
	return (z);
}

static int connect_init(t_connect *connect)
{
	connect->connect = mlx_init();
	if (!(connect->connect))
		return(1);
	connect->mlx_win = mlx_new_window(connect->connect, WD, HG, "fractol");
	if (!(connect->mlx_win))
		return(1);
	connect->img = mlx_new_image(connect->connect, WD, HG);
	if (!(connect->img))
		return(1);
	connect->addr = (int *)mlx_get_data_addr(connect->img,
											  &connect->bites_per_px,&connect->line_length, &connect->endian);
	if (!(connect->addr))
		return (1);

	return (0);
}

int	mandelbro_dr(t_frctl *frctl)
{
	t_cmplx z;
	frctl->mtrx->x = 0;
	frctl->mtrx->y = 0;
	int iter = 0;

	while (frctl->mtrx->y < HG)
	{

		while (frctl->mtrx->x < WD)
		{
			z = ft_get_real(frctl);
			while (iter < frctl->mtrx->max_i)
			{
				z = calc_fract(frctl, z);
				if (z.re*z.re - z.im*z.im > 16)
					break;
				iter++;
			}
			++frctl->mtrx->x;
			frctl->mlx->addr[PIX] = (iter == frctl->mtrx->max_i) ? 1 :
					get_trgb(1, 25, 255, 255);
		}
		++frctl->mtrx->y;
	}
	return 0;
}

int mandelbrot (t_frctl *frctl)
{
	frctl->mtrx->max_x = 2.0;
	frctl->mtrx->max_y = 2.0;
	frctl->mtrx->min_x = -2.0;
	frctl->mtrx->min_y = -2.0;
	frctl->mtrx->max_i = 25;
	frctl->mtrx->iter = 0;
	mandelbro_dr(frctl);
	return 0;
}

int main()
{
	printf("ew");
	t_frctl *frctl;
	frctl = (t_frctl*)malloc(sizeof(t_frctl));
	if (!frctl)
		return (0);
	frctl->mlx = (t_connect*)malloc(sizeof(t_connect));
	if (!frctl->mlx)
		return (0);
	frctl->mtrx = (t_mtrx*)malloc(sizeof(t_frctl));
	if (!frctl->mtrx)
		return (0);
	frctl->cmplx = (t_cmplx*)malloc(sizeof(t_cmplx));
	if (!frctl->cmplx)
		return (0);
	connect_init(frctl->mlx);
	mandelbrot(frctl);
	mlx_put_image_to_window(frctl->mlx->connect, frctl->mlx->mlx_win,
							frctl->mlx->img, 0, 0);
	mlx_loop(frctl->mlx->connect);
}

