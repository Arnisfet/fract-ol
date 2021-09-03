#include "../fractol.h"

int	mandelbrot(t_frctl *frctl)
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
	frctl->mtrx->flag = 'm';
	frctl->mtrx->rgb[0] = 232;
	frctl->mtrx->rgb[1] = 179;
	frctl->mtrx->rgb[2] = 212;
	mandelbro_dr(frctl);
	return (0);
}

int	mandelbro_dr(t_frctl *frctl)
{
	int	n;

	while (frctl->mtrx->y < HG)
	{
		frctl->mtrx->x = 0;
		while (frctl->mtrx->x < WD)
		{
			frctl->mtrx->PIX = frctl->mtrx->y * WD + frctl->mtrx->x;
			get_toReal(frctl->mtrx->x, frctl->mtrx->y, frctl);
			n = findMandelbrot(frctl->mtrx->cre, frctl->mtrx->cim, frctl);
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

int	findMandelbrot(double cr, double ci, t_frctl *frctl)
{
	double	NewRe;
	double	NewIm;
	int		iter;
	double	oldRe;
	double	oldIm;

	NewRe = 0.0;
	NewIm = 0.0;
	iter = 0;
	while (iter < frctl->mtrx->max_i && NewRe * NewRe + NewIm * NewIm <= 4.0)
	{
		oldRe = NewRe;
		oldIm = NewIm;
		NewRe = oldRe * oldRe - oldIm * oldIm + cr;
		NewIm = 2 * oldRe * oldIm + ci;
		iter++;
	}
	return (iter);
}
