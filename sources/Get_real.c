#include "../fractol.h"

double	get_toReal(int x, int y, t_frctl *frctl)
{
	double	Range_x;
	double	Range_y;

	Range_x = (frctl->mtrx->max_x - frctl->mtrx->min_x) / (WD - 1);
	Range_y = (frctl->mtrx->max_y - frctl->mtrx->min_y) / (HG - 1);
	frctl->mtrx->cre = frctl->mtrx->min_x + x * Range_x;
	frctl->mtrx->cre /= frctl->mtrx->scale;
	frctl->mtrx->cre += frctl->mtrx->offset_x;
	frctl->mtrx->cim = frctl->mtrx->max_y - y * Range_y;
	frctl->mtrx->cim /= frctl->mtrx->scale;
	frctl->mtrx->cim += frctl->mtrx->offset_y;
	return (0);
}
