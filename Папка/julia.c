#include "fractol.h"

int	julia(t_frctl *frctl)
{
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
	frctl->mtrx->flag = 'j';
	julia_dr(frctl);
	return (0);
}

int	julia_dr(t_frctl *frctl)
{
	double	cRe;
	double	cIm;
	int		n;

	cIm = frctl->mtrx->cim;
	cRe = frctl->mtrx->cre;
	while (frctl->mtrx->y < HG)
	{
		frctl->mtrx->x = 0;
		while (frctl->mtrx->x < WD)
		{
			n = find_Julia(cRe, cIm, frctl);
			if (n != frctl->mtrx->max_i)
				color(n, frctl);
			else
				frctl->mlx->addr[PIX] = get_trgb(1, 225, 225, 225);
			++frctl->mtrx->x;
		}
		++frctl->mtrx->y;
	}
	frctl->mtrx->y = 0;
	return (0);
}

int	find_Julia(double cRe, double cIm, t_frctl *frctl)
{
	int		iter;
	double	newRe;
	double	newIm;
	double	oldRe;
	double	oldIm;

	iter = 0;
	newRe = 1.5 * (frctl->mtrx->x - WD / 2) / (0.5 * WD);
	newIm = (frctl->mtrx->y - HG / 2) / (0.5 * HG);
	newRe /= frctl->mtrx->scale;
	newIm /= frctl->mtrx->scale;
	newRe += frctl->mtrx->offset_x;
	newIm += frctl->mtrx->offset_y;
	while (iter < frctl->mtrx->max_i && newRe * newRe + newIm * newIm <= 4.0)
	{
		oldRe = newRe;
		oldIm = newIm;
		newRe = oldRe * oldRe - oldIm * oldIm + cRe;
		newIm = 2 * oldRe * oldIm + cIm;
		iter++;
	}
	return (iter);
}
//double cRe = -0.79, cIm = -0.27;	double cRe = -0.59, cIm = -0.47;