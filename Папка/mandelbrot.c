#include "fractol.h"

int mandelbrot(t_frctl *frctl)
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
    frctl->mtrx->max_y = frctl->mtrx->min_y + (frctl->mtrx->max_x - frctl->mtrx->min_y) * HG / WD;
    frctl->mtrx->scale = 1;
    frctl->mtrx->flag = 'm';
    frctl->mtrx->rgb[0] = 23;
    frctl->mtrx->rgb[1] = 5;
    frctl->mtrx->rgb[2] = 78;
    mandelbro_dr(frctl);
    return 0;
}

int	mandelbro_dr(t_frctl *frctl)
{
	while (frctl->mtrx->y < HG)
	{

		double ci = get_y_toReal(frctl, frctl->mtrx->y);
		frctl->mtrx->x = 0;
		while (frctl->mtrx->x < WD)
		{
			double cr = get_x_toReal(frctl, frctl->mtrx->x);
			int n = findMandelbrot(cr, ci, frctl);
			if (n != frctl->mtrx->max_i)
				color(n, frctl);
			else
				frctl->mlx->addr[PIX] = get_trgb(1, 225, 225, 225);
			++frctl->mtrx->x;
		}
		++frctl->mtrx->y;
	}
	frctl->mtrx->y = 0;
	return 0;
}

int findMandelbrot(double cr, double ci, t_frctl *frctl)
{
    double zr = 0.0, zi = 0.0;
    int iter;

    iter = 0;
    while (iter < frctl->mtrx->max_i && zr * zr + zi * zi <= 4.0)
    {
        double tempX = (zr * zr) - (zi * zi) + cr;
        zi = (2.0 * zr * zi) + ci;
        zr = tempX;
        iter++;
    }
    return (iter);
}
