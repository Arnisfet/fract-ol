
#include "fractol.h"

typedef struct	s_factor
{
	double f_re;
	double	f_im;
	double	calc_re;
	double	calc_im;
}				t_factor;

typedef struct	t_struct
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		*addr;
	int		bites_per_px;
	int		line_length;
	int		endian;
}				s_struct;


typedef struct	cmplx_struct
{
	double	max_re;
	double	min_re;
	double	min_im;
	double	max_im;
}				s_complx;

static int connect_init(s_struct *point)
{
	point->mlx = mlx_init();
	if (!(point->mlx))
		return(1);
point->mlx_win = mlx_new_window(point->mlx, WD, HG, "fractol");
if (!(point->mlx_win))
	return(1);
point->img = mlx_new_image(point->mlx, WD, HG);
if (!(point->img))
	return(1);
point->addr = (int *)mlx_get_data_addr(point->img, &point->bites_per_px,
								&point->line_length, &point->endian);
if (!(point->addr))
	return (1);
return (0);
}

int get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int main() {
	s_struct *point;
	s_complx compl;
	t_factor fac;
	int r, g, b;
	r = 25;
	g = 255;
	b = 255;
	//Определение границ комплексной плоскости
	compl.min_re = -2.0;
	compl.max_re = 2.0;
	compl.min_im = -2.0;
	compl.max_im = compl.min_im + (compl.max_re - compl.min_re) * HG / WD;
	//Расчет связи с декартовой системой
	fac.f_re = (compl.max_re - compl.min_re) / (WD - 1);
	fac.f_im = (compl.max_im - compl.min_im) / (HG - 1);
	//Кол-во итераций
	int iter = 50;
	point = (s_struct*)malloc(sizeof(s_struct));
	if (!point)
		return (0);
	connect_init(point);
	int y = 0;
	int x = 0;
	while (y < HG)
	{
		fac.calc_im = compl.max_im - y * fac.f_im;
		x = 0;
		while (x < WD)
		{
			fac.calc_re = compl.min_re + x * fac.f_re;
			x++;
		}
		y++;
	}
}