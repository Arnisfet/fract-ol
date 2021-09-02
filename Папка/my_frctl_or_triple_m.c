//
// Created by Mickey Rudge on 8/30/21.
//

#include "fractol.h"

// Найти целую и мнимую часть комплексного числа

int	my_frctl(t_frctl *frctl)
{
	frctl->mtrx->offset_y = 0;
	frctl->mtrx->offset_x = 0;
	frctl->mtrx->max_x = 2.0;
	frctl->mtrx->min_x = -2.0;
	frctl->mtrx->min_y = -2.0;
	frctl->mtrx->max_i = 1000;
	frctl->mtrx->iter = 0;
	frctl->mtrx->x = 0;
	frctl->mtrx->y = 0;
	frctl->mtrx->max_y = frctl->mtrx->min_y + (frctl->mtrx->max_x
			- frctl->mtrx->min_y) * HG / WD;
	frctl->mtrx->scale = 1;
	frctl->mtrx->flag = 'f';
	frctl->mtrx->rgb[0] = 23;
	frctl->mtrx->rgb[1] = 5;
	frctl->mtrx->rgb[2] = 78;
	frctl_dr(frctl);
	return (0);
}

int	find_my_frctl(double cr, double ci, t_frctl *frctl)
{
	double	zr;
	double	zi;
	int		iter;
	double	tempX;

	iter = 0;
	zr = 0.0;
	zi = 0.0;
	while (iter < frctl->mtrx->max_i && zr * zr + zi * zi <= 4.0)
	{
		tempX = pow(zr, 2) - pow(zi, 2) + cr;
		zi = 2.0 * zr * zi + ci;
		zr = tempX;
		zi *= -1;
		iter++;
	}
	return (iter);
}

int	frctl_dr(t_frctl *frctl)
{
	int	n;

	while (frctl->mtrx->y < HG)
	{
		frctl->mtrx->x = 0;
		while (frctl->mtrx->x < WD)
		{
			frctl->mtrx->PIX = frctl->mtrx->y * WD + frctl->mtrx->x;
			get_toReal(frctl->mtrx->x, frctl->mtrx->y, frctl);
			n = find_my_frctl(frctl->mtrx->cre, frctl->mtrx->cim, frctl);
			if (n != frctl->mtrx->max_i)
				color(n, frctl);
			else
				frctl->mlx->addr[frctl->mtrx->PIX] = get_trgb(1, 225, 225, 225);
			++frctl->mtrx->x;
		}
		++frctl->mtrx->y;
	}
	frctl->mtrx->y = 0;
	return (0);
}
