//
// Created by Mickey Rudge on 8/26/21.
//
#include "fractol.h"

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