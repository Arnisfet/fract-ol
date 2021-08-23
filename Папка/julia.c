#include "fractol.h"

int julia(t_frctl *frctl)
{
	frctl->mtrx->max_x = 2.0;
	frctl->mtrx->min_x = -2.0;
	frctl->mtrx->min_y = -2.0;
	frctl->mtrx->max_i = 1000;
	frctl->mtrx->iter = 0;
	frctl->mtrx->x = 0;
	frctl->mtrx->y = 0;
	frctl->mtrx->max_y = frctl->mtrx->min_y + (frctl->mtrx->max_x - frctl->mtrx->min_y) * HG / WD;
	frctl->mtrx->scale = 1;
	frctl->mtrx->flag = 'j';
	julia_dr(frctl);
	return 0;
}

int find_Julia(double cRe, double cIm, t_frctl *frctl)
{
	int iter;

	iter = 0;
	double newRe = 1.5 * (frctl->mtrx->x - WD / 2) / (0.5 * WD);
	double newIm = (frctl->mtrx->y - HG / 2) / (0.5 * HG);
	while (iter < frctl->mtrx->max_i && newRe * newRe + newIm * newIm <= 4.0)
	{
		double oldRe = newRe;
		double oldIm = newIm;
		newRe = oldRe * oldRe - oldIm * oldIm +cRe;
		newIm = 2 * oldRe*oldIm + cIm;
		iter++;
	}
	return (iter);
}

int julia_dr(t_frctl *frctl)
{
	double cRe = -0.670, cIm = -0.34;
	while (frctl->mtrx->y < HG)
	{
		frctl->mtrx->x = 0;
		while (frctl->mtrx->x < WD)
		{
			int n = find_Julia(cRe, cIm, frctl);
			if (n != frctl->mtrx->max_i)
				frctl->mlx->addr[PIX] = get_trgb(1, (220/n*10)+n, (50/n)+n,
												 (255+n)+n);
			else
				frctl->mlx->addr[PIX] = get_trgb(1, 225, 225, 225);
			++frctl->mtrx->x;
		}
		++frctl->mtrx->y;
	}
	return 0;
}


