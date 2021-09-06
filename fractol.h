//
// Created by vitya on 02.08.2021.
//

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "./includes/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"
# define WD 500
# define HG 500
# define ESC 53
# define SCRL_UP 4
# define SCRL_DOWN 5
# define R 15
# define G 5
# define B 11
# define Z 6
# define X 7
# define W 13
# define S 1
# define D 2
# define A 0
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

typedef struct t_struct
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
	double	re;
	double	im;
	double	aa;
	double	twoab;
	double	ca;
	double	cb;
}				t_cmplx;

typedef struct s_struct
{
	double	offset_x;
	double	offset_y;
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;
	double	scale;
	int		max_i;
	int		x;
	int		y;
	int		iter;
	double	cre;
	double	cim;
	double	cre_2;
	double	cim_2;
	char	flag;
	int		rgb[3];
	int		PIX;
	t_cmplx	z;
}				t_mtrx;

typedef struct s_frctl
{
	t_connect	*mlx;
	t_mtrx		*mtrx;
	t_cmplx		*cmplx;
}				t_frctl;

int		get_trgb(int t, int r, int g, int b);
int		mandelbrot(t_frctl *frctl);
int		mandelbro_dr(t_frctl *frctl);
int		findMandelbrot(double cr, double ci, t_frctl *frctl);
int		julia(t_frctl *frctl);
int		julia_dr(t_frctl *frctl);
double	get_toReal(int x, int y, t_frctl *frctl);
int		find_Julia(double cRe, double cIm, t_frctl *frctl);
int		key_hook(int key_code, t_frctl *frctl);
int		ft_exit(t_frctl *frctl);
int		ft_keyboard(int keycode, t_frctl *frctl);
int		ft_mouse(int button, int x, int y, t_frctl *frctl);
void	ft_malloc_fr(t_frctl *frctl);
void	ft_puterror(char *str, t_frctl *frctl);
void	ft_hook(t_frctl *frctl);
int		find_serpinskiy(int x, int y, t_frctl *frctl);
int		serpinskiy_dr(t_frctl *frctl);
void	serpinskiy(t_frctl *frctl);
void	ft_put_fr_towin(t_frctl *frctl);
int		color(int n, t_frctl *frctl);
int		burning_ship(t_frctl *frctl);
int		burn_dr(t_frctl *frctl);
int		findBurningship(double cr, double ci, t_frctl *frctl);
void	next_draw(t_frctl *frctl);
int		ft_change_color(t_frctl *frctl, int keycode);
int		my_frctl(t_frctl *frctl);
int		frctl_dr(t_frctl *frctl);
int		ft_motion(int x, int y, t_frctl *frctl);
int		ft_choose(char **argv, t_frctl *frctl, int ac);
int		choose_julia(t_frctl *frctl, char **argv);
int		ft_move_frctl(int keycode, t_frctl *frctl);
#endif //MLX_FRACTOL_H
