#include "fractol.h"

// Найти целую и мнимую часть комплексного числа

double get_x_toReal(t_frctl *frctl, int x)
{
    double Range = (frctl->mtrx->max_x - frctl->mtrx->min_x) / (WD - 1);
    return (frctl->mtrx->min_x + x * Range);
}

double get_y_toReal(t_frctl *frctl, int y)
{
	double Range = (frctl->mtrx->max_y - frctl->mtrx->min_y) / (HG - 1);
	return (frctl->mtrx->max_y - y * Range);
}

int mandelbrot(t_frctl *frctl)
{
    frctl->mtrx->max_x = 2.0;
    frctl->mtrx->min_x = -2.0;
    frctl->mtrx->min_y = -2.0;
    frctl->mtrx->max_i = 25;
    frctl->mtrx->iter = 0;
    frctl->mtrx->x = 0;
    frctl->mtrx->y = 0;
    frctl->mtrx->max_y = frctl->mtrx->min_y + (frctl->mtrx->max_x - frctl->mtrx->min_y) * HG / WD;
    mandelbro_dr(frctl);
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
                frctl->mlx->addr[PIX] = get_trgb(1, 220+n, 50, 220/n);
            else
            	frctl->mlx->addr[PIX] = 0;
            ++frctl->mtrx->x;
        }
        ++frctl->mtrx->y;
    }

    mlx_put_image_to_window(frctl->mlx->connect, frctl->mlx->mlx_win, frctl->mlx->img, 0, 0);
    return 0;
}