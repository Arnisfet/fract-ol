//
// Created by Mickey Rudge on 8/16/21.
//

#include "fractol.h"

int get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}