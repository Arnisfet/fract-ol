
#include "fractol.h"

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


typedef struct	cmplx_struct
{
	float	x;
	float	y;
	float	z;
}				s_complx;

static int connect_init(t_connect *point)
{
	point->connect = mlx_init();
	if (!(point->connect))
		return(1);
	point->mlx_win = mlx_new_window(point->connect, WD, HG, "fractol");
	if (!(point->mlx_win))
		return(1);
	point->img = mlx_new_image(point->connect, WD, HG);
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
	t_connect *point;
	int y = 0;
	int x = 0;
	int r, g, b;
	r = 25;
	g = 255;
	b = 255;

	point = (t_connect*)malloc(sizeof(t_connect));
	if (!point)
		return (0);
	connect_init(point);
	while (y != WD)
	{
		while (x != HG)
		{
			if (x%20)
				point->addr[y * WD + x] = get_trgb(1, r, g, b);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(point->connect, point->mlx_win, point->img, 0, 0);
	mlx_loop(point->connect);
}