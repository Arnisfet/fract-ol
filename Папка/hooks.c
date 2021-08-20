//
// Created by Mickey Rudge on 8/20/21.
//

#include "fractol.h"

int ft_exit(t_frctl *frctl)
{
	if (frctl != NULL)
	{
		if(frctl->mlx != NULL)
		free(frctl->mlx);
		if(frctl->mtrx != NULL)
			free(frctl->mtrx);
		if(frctl->cmplx != NULL)
			free(frctl->cmplx);
		free(frctl);
	}
	exit (0);
	return(0);
}

int ft_keyboard(int keycode, t_frctl *frctl)
{
	if (keycode == ESC)
		ft_exit(frctl);
}