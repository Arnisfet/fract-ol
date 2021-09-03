//
// Created by Mickey Rudge on 9/2/21.
//

#include "../fractol.h"

int	ft_mouse(int button, int x, int y, t_frctl *frctl)
{
	x = 0;
	y = 0;
	x = y;
	if (button == SCRL_UP)
		frctl->mtrx->scale *= 1.1;
	if (button == SCRL_DOWN)
		frctl->mtrx->scale /= 1.1;
	next_draw(frctl);
	return (0);
}

int	ft_motion(int x, int y, t_frctl *frctl)
{
	x = 0;
	y = 0;
	x = y;
	if (frctl->mtrx->flag == 'j')
	{
		frctl->mtrx->cim += 0.002;
		frctl->mtrx->cre += 0.002;
	}
	next_draw(frctl);
	return (0);
}
