//
// Created by Mickey Rudge on 8/20/21.
//

#include "fractol.h"

void	ft_hook(t_frctl *frctl)
{
	mlx_hook(frctl->mlx->mlx_win, 2, 0, ft_keyboard, frctl);
	mlx_hook(frctl->mlx->mlx_win, 17, 5, ft_exit, frctl);
	mlx_hook(frctl->mlx->mlx_win, 4, 0, ft_mouse, frctl);
	mlx_hook(frctl->mlx->mlx_win, 6, 0, ft_motion, frctl);
}

int	ft_motion(int x, int y, t_frctl *frctl)
{
	if (frctl->mtrx->flag == 'j')
	{
		frctl->mtrx->cim += 0.002;
		frctl->mtrx->cre += 0.002;
	}
	next_draw(frctl);
	return (0);
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

int	ft_change_color(t_frctl *frctl, int keycode)
{
	if (keycode == R)
		frctl->mtrx->rgb[0] += 10;
	if (keycode == G)
		frctl->mtrx->rgb[1] += 10;
	if (keycode == B)
		frctl->mtrx->rgb[2] += 10;
	next_draw(frctl);
	return (0);
}

int	ft_move_frctl(int keycode, t_frctl *frctl)
{
	if (keycode == W || keycode == UP)
		frctl->mtrx->offset_y -= 0.5 / frctl->mtrx->scale;
	if (keycode == S || keycode == DOWN)
		frctl->mtrx->offset_y += 0.5 / frctl->mtrx->scale;
	if (keycode == A || keycode == LEFT)
		frctl->mtrx->offset_x -= 0.5 / frctl->mtrx->scale;
	if (keycode == D || keycode == RIGHT)
		frctl->mtrx->offset_x += 0.5 / frctl->mtrx->scale;
	next_draw(frctl);
	return (0);
}

int	ft_keyboard(int keycode, t_frctl *frctl)
{
	if (keycode == ESC)
		ft_exit(frctl);
	else if (keycode == R || keycode == G || keycode == B)
		ft_change_color(frctl, keycode);
	else if (keycode == Z)
	{
		frctl->mtrx->cim += 0.002;
		next_draw(frctl);
	}
	else if (keycode == X)
	{
		frctl->mtrx->cre += 0.002;
		next_draw(frctl);
	}
	else if (keycode == W || keycode == A || keycode == S || keycode == D
		||keycode == UP || keycode == LEFT || keycode == DOWN
		|| keycode == RIGHT)
		ft_move_frctl(keycode, frctl);
	return (0);
}

int	ft_mouse(int button, int x, int y, t_frctl *frctl)
{
	if (button == SCRL_UP)
		frctl->mtrx->scale *= 1.1;
	if (button == SCRL_DOWN)
		frctl->mtrx->scale /= 1.1;
	next_draw(frctl);
	return (0);
}

void	next_draw(t_frctl *frctl)
{
	mlx_clear_window(frctl->mlx->connect, frctl->mlx->mlx_win);
	ft_put_fr_towin(frctl);
	mlx_put_image_to_window(frctl->mlx->connect, frctl->mlx->mlx_win,
		frctl->mlx->img, 0, 0);
}
