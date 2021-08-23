//
// Created by vitya on 02.08.2021.
//

#ifndef MLX_FRACTOL_H
#define MLX_FRACTOL_H
#include "./includes/libft.h"
#include <math.h>
#include "includes/mlx.h"
#include <stdlib.h>
#include <stdio.h>
# define WD 1000
# define HG 1000
# define PIX (frctl->mtrx->y * WD + frctl->mtrx->x)
# define ESC 53
# define SCRL_UP 4

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
	double offset_x;
	double offset_y;
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
	char flag;
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
int	mandelbro_dr(t_frctl *frctl);
int findMandelbrot(double cr, double ci, t_frctl *frctl);
int julia(t_frctl *frctl);
int julia_dr(t_frctl *frctl);
double get_y_toReal(t_frctl *frctl, int y);
double get_x_toReal(t_frctl *frctl, int x);
int find_Julia(double cRe, double cIm, t_frctl *frctl);
int key_hook(int key_code, t_frctl *frctl);
int ft_exit(t_frctl *frctl);
int ft_keyboard(int keycode, t_frctl *frctl);
int ft_mouse(int keycode, t_frctl *frctl);
void ft_malloc_fr(t_frctl *frctl);
void	ft_puterror(char *str, t_frctl *frctl);
void ft_hook(t_frctl *frctl);
int find_serpinskiy(int x, int y, t_frctl *frctl);
int	serpinskiy_dr(t_frctl *frctl);
int serpinskiy(t_frctl *frctl);
int	ft_put_fr_towin(t_frctl *frctl);


#endif //MLX_FRACTOL_H
