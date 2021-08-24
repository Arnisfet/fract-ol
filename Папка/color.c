/* Алгоритм закраски в цикле:
 * Суть цикла в прохождении всех возможных вариантов фейс-контролей(n).
 *   max_i/i    max_i/i-10           max_i/2
 * <-----.----------.------------------.---------------------------------> Ось значений (max i)
 * Все значения до max_i/2 в теории просчитываются в первом условии, все, что больше max_i/2 проходится во втором условии
 * С каждым проходом цикла уменьшаем счетчик итераций на 1 и прибавляем к цвету 5 единиц для получения максимально
 * насыщенных цветов для почи "презентабельных" точек.
 *
 * В функцию min_color попадают самые "слабые" (гоповатые точки) и закрашиваются в большом количестве.
 * */
#include "fractol.h"

int get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void    min_color(t_frctl *frctl, int n, int *rgb)
{
    if (n == 1)
        frctl->mlx->addr[PIX] = get_trgb(1, rgb[0], rgb[1], rgb[2]+1);
    else if (n == 2 || n == 3)
        frctl->mlx->addr[PIX] = get_trgb(1, rgb[0], rgb[1], rgb[2]+2);
    else if (n == 4 || n == 5)
        frctl->mlx->addr[PIX] = get_trgb(1, rgb[0], rgb[1], rgb[2]+3);
    else if (n == 6 || n == 7)
        frctl->mlx->addr[PIX] = get_trgb(1, rgb[0], rgb[1], rgb[2]+4);
    else if (n == 8 || n == 9)
        frctl->mlx->addr[PIX] = get_trgb(1, rgb[0], rgb[1], rgb[2]+5);
}

int color (int n, t_frctl *frctl)
{
    int rgb[3];
    int i;

    rgb[0] = 26;
    rgb[1] = 0;
    rgb[2] = 74;
    i = frctl->mtrx->max_i/2;
    min_color(frctl, n, rgb);
    while (i != 0)
    {
        if (n > i)
        {
            if (n >= frctl->mtrx->max_i/i)
                frctl->mlx->addr[PIX] = get_trgb(1, rgb[0], rgb[1], rgb[2]);
        }
        i -= 1, rgb[2] += 5;
    }
}

