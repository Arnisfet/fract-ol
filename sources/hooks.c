//
// Created by Mickey Rudge on 8/20/21.
//

#include "../fractol.h"

void	ft_hook(t_frctl *frctl)
{
	mlx_hook(frctl->mlx->mlx_win, 2, 0, ft_keyboard, frctl);
	mlx_hook(frctl->mlx->mlx_win, 17, 5, ft_exit, frctl);
	mlx_hook(frctl->mlx->mlx_win, 4, 0, ft_mouse, frctl);
	mlx_hook(frctl->mlx->mlx_win, 6, 0, ft_motion, frctl);
}

int	ft_exit(t_frctl *frctl)
{
	if (frctl != NULL)
	{
		if (frctl->mlx != NULL)
			free(frctl->mlx);
		if (frctl->mtrx != NULL)
			free(frctl->mtrx);
		if (frctl->cmplx != NULL)
			free(frctl->cmplx);
		free(frctl);
	}
	exit (0);
}

void	next_draw(t_frctl *frctl)
{
	mlx_clear_window(frctl->mlx->connect, frctl->mlx->mlx_win);
	ft_put_fr_towin(frctl);
	mlx_put_image_to_window(frctl->mlx->connect, frctl->mlx->mlx_win,
		frctl->mlx->img, 0, 0);
}
