//
// Created by vitya on 02.08.2021.
//

#ifndef MLX_FRACTOL_H
#define MLX_FRACTOL_H
#include <math.h>
#include "./minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
# define WD 1000
# define HG 1000
# define PIX (frctl->mtrx->y * WD + frctl->mtrx->x)

typedef struct	t_struct
{
	void	*connect;
	void	*mlx_win;
	void	*img;
	int		*addr;
	int		bites_per_px;
	int		line_length;
	int		endian;
}				t_connect;

typedef struct s_cmplx
{
	double re;
	double im;
	double aa;
	double twoab;
	double ca;
	double cb;
}				t_cmplx;

typedef struct s_struct
{
	double max_x;
	double min_x;
	double max_y;
	double min_y;
	double scale;
	int max_i;
	int x;
	int y;
	int iter;
	int color;
	t_cmplx z;
}				t_mtrx;

typedef struct s_frctl
{
	t_connect *mlx;
	t_mtrx *mtrx;
	t_cmplx *cmplx;
}				t_frctl;

int get_trgb(int t, int r, int g, int b);
int mandelbrot (t_frctl *frctl);
int main();
int	mandelbro_dr(t_frctl *frctl);
int findMandelbrot(double cr, double ci, t_frctl *frctl);
int julia(t_frctl *frctl);
int julia_dr(t_frctl *frctl);
double get_y_toReal(t_frctl *frctl, int y);
double get_x_toReal(t_frctl *frctl, int x);

#endif //MLX_FRACTOL_H
