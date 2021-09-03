//
// Created by Mickey Rudge on 8/23/21.
//
#include "../fractol.h"

void	serpinskiy(t_frctl *frctl)
{
	frctl->mtrx->offset_y = 0;
	frctl->mtrx->offset_x = 0;
	frctl->mtrx->max_x = 2.0;
	frctl->mtrx->min_x = -2.0;
	frctl->mtrx->min_y = -2.0;
	frctl->mtrx->max_i = 5;
	frctl->mtrx->iter = 0;
	frctl->mtrx->x = 0;
	frctl->mtrx->y = 0;
	frctl->mtrx->scale = 1;
	frctl->mtrx->flag = 's';
	serpinskiy_dr(frctl);
}

int	find_serpinskiy(int x, int y, t_frctl *frctl)
{
	int	i;

	i = 0;
	while (i < frctl->mtrx->max_i)
	{
		x /= frctl->mtrx->scale;
		y /= frctl->mtrx->scale;
		x += frctl->mtrx->offset_x;
		y += frctl->mtrx->offset_y;
		if ((x % 3 == 1) && (y % 3 == 1))
			return (0);
		x /= 3;
		y /= 3;
		i++;
	}
	return (i);
}

int	serpinskiy_dr(t_frctl *frctl)
{
	int	n;

	while (frctl->mtrx->y < HG)
	{
		frctl->mtrx->x = 0;
		while (frctl->mtrx->x < WD)
		{
			frctl->mtrx->PIX = frctl->mtrx->y * WD + frctl->mtrx->x;
			n = find_serpinskiy(frctl->mtrx->x, frctl->mtrx->y, frctl);
			if (n == 0)
				frctl->mlx->addr[frctl->mtrx->PIX] = get_trgb(1, 225, 225, 225);
			else
				frctl->mlx->addr[frctl->mtrx->PIX] = get_trgb(1, 30, 50, 205);
			++frctl->mtrx->x;
		}
		++frctl->mtrx->y;
	}
	frctl->mtrx->y = 0;
	return (0);
}
