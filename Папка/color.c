/* Алгоритм закраски в цикле:
 * Суть цикла в прохождении всех возможных вариантов фейс-контролей(n).
 *   max_i/i    max_i/i-10           max_i/2
 * <-----.----------.------------------.------------------------------->(max i)
 * Все значения до max_i/2 в теории просчитываются в первом условии, все,
 * что больше max_i/2 проходится во втором условии
 * С каждым проходом цикла уменьшаем счетчик итераций на 1 и прибавляем
 * к цвету 5 единиц для получения максимально
 * насыщенных цветов для почи "презентабельных" точек.
 *
 * В функцию min_color попадают самые "слабые" (гоповатые точки) и
 * закрашиваются в большом количестве.
 * */
#include "fractol.h"

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	min_color(t_frctl *frctl, int n)
{
	if (n == 1)
		frctl->mlx->addr[frctl->mtrx->PIX] = get_trgb(1,
				 frctl->mtrx->rgb[0], frctl->mtrx->rgb[1],
				 frctl->mtrx->rgb[2]);
	if (n == 2 || n == 3)
		frctl->mlx->addr[frctl->mtrx->PIX] = get_trgb(1,
				frctl->mtrx->rgb[0] + 2, frctl->mtrx->rgb[1],
				frctl->mtrx->rgb[2]);
	if (n == 4 || n == 5)
		frctl->mlx->addr[frctl->mtrx->PIX] = get_trgb(1, frctl->mtrx->rgb[0]
				+ 5, frctl->mtrx->rgb[1], frctl->mtrx->rgb[2]);
	if (n == 6 || n == 7)
		frctl->mlx->addr[frctl->mtrx->PIX] = get_trgb(1,
				 frctl->mtrx->rgb[0] + 7, frctl->mtrx->rgb[1],
				 frctl->mtrx->rgb[2]);
	if (n == 8 || n == 9)
		frctl->mlx->addr[frctl->mtrx->PIX] = get_trgb(1,
				 frctl->mtrx->rgb[0] + 9, frctl->mtrx->rgb[1],
				 frctl->mtrx->rgb[2]);
}

int	color(int n, t_frctl *frctl)
{
	int	i;
	int	rg[3];

	rg[0] = frctl->mtrx->rgb[0];
	rg[1] = frctl->mtrx->rgb[1];
	rg[2] = frctl->mtrx->rgb[2];
	i = frctl->mtrx->max_i / 2;
	min_color(frctl, n);
	while (i != 0)
	{
		if (n < frctl->mtrx->max_i && n > 10)
		{
			if (n >= frctl->mtrx->max_i / i)
				frctl->mlx->addr[frctl->mtrx->PIX]
					= get_trgb(1, rg[0], rg[1], rg[2]);
		}
		i--, rg[1] += 2;
	}
	return (0);
}
