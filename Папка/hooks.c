//
// Created by Mickey Rudge on 8/20/21.
//

#include "fractol.h"

void ft_hook(t_frctl *frctl)
{
	mlx_hook(frctl->mlx->mlx_win, 17, 0, ft_exit, frctl);
	mlx_hook(frctl->mlx->mlx_win, 2, 0, ft_keyboard, frctl);
	mlx_hook(frctl->mlx->mlx_win, 4, 0, ft_mouse, frctl);
}

int ft_exit(t_frctl *frctl)
{
	if (frctl != NULL)
	{
		if(frctl->mlx != NULL)
		free(frctl->mlx);
		if(frctl->mtrx != NULL)
			free(frctl->mtrx);
		if(frctl->cmplx != NULL)
			free(frctl->cmplx);
		free(frctl);
	}
	exit (0);
}

int ft_keyboard(int keycode, t_frctl *frctl)
{
	if (keycode == ESC)
		ft_exit(frctl);
}

int ft_mouse(int keycode, t_frctl *frctl)
{
	if (keycode == SCRL_UP)
	{
		frctl->mtrx->scale *= 1.1;
	}
	mlx_clear_window(frctl->mlx->connect, frctl->mlx->mlx_win);
	ft_put_fr_towin(frctl);
	return 0;
}