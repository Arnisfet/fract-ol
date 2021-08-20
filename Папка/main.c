
#include "fractol.h"

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
	connect->addr = (int *)mlx_get_data_addr(connect->img,&connect->bites_per_px,&connect->line_length, &connect->endian);
	if (!(connect->addr))
		return (1);
	return (0);
}

int ft_hook(t_frctl *frctl)
{
	mlx_hook(frctl->mlx->mlx_win, 17, 0, ft_exit, frctl);
	mlx_hook(frctl->mlx->mlx_win, 2, 0, ft_keyboard, frctl);
}


int main()
{
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
//	mandelbrot(frctl);
	julia(frctl);
	mlx_put_image_to_window(frctl->mlx->connect, frctl->mlx->mlx_win,
							frctl->mlx->img, 0, 0);
	ft_hook(frctl);
	mlx_loop(frctl->mlx->connect);
	return 0;
}

