
#include "fractol.h"

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

typedef struct	s_struct
{
//	ограничения на плоскости
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
//	отрисовка с центра экрана
	double	calc_re;
	double	calc_im;
//	Запоминание числа
	double z_re;
	double z_im;
}				t_factorial;

typedef struct c_struct
{
//	Получение полноценного комплексного числа с центра координат
	double c_re;
	double c_im;

}				t_complex;

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

t_factorial init_complex(double re, double im)
{
	t_factorial complex;
	complex.min_re = re;
	complex.min_im = im;
	return (complex);
}

int main()
{
	s_struct	*point;
	t_factorial	f;
	t_complex	c;
	t_factorial	z;
	int x, y, max_iter, iter, r, g, b;

	r = 25, g = 255, b = 255;
	y = 0, max_iter = 50;
	point = (s_struct*)malloc(sizeof(s_struct));
	if (!point)
		return (0);
	connect_init(point);
	f = init_complex(-2.0, -2.0);
	f.min_im = -2.0;
	f.max_im = f.min_im + (f.max_re - f.min_re) * HG/WD;
	f.calc_re = (f.max_re - f.min_re) / (WD - 1);
	f.calc_im = (f.max_im - f.min_im) / (HG - 1);

	while (y < HG)
	{
		c.c_im = f.max_im - y * f.calc_im;
		x = 0;
		while (x < WD)
		{
			c.c_re = f.min_re + x * f.calc_re;
			z = init_complex(c.c_re, c.c_im);
			iter = 0;
			while (pow(c.c_re, 2.0) + pow(c.c_im, 2.0) <= 4
			&& iter < max_iter)
			{
				z = init_complex(
						pow(z.z_re, 2.0) - pow(z.z_im, 2.0),
						2.0 * z.z_re * z.z_im + c.c_im);
				iter++;
			}
			point->addr[PIX] = get_trgb(1, r, g, b);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(point->mlx, point->mlx_win, point->img, 0, 0);
	mlx_loop(point->mlx);
}