
#include "fractol.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	int		i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char*)str1;
	s2 = (char*)str2;
	while (s1[i] == s2[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_puterror(char *str, t_frctl *frctl)
{
	if (frctl != NULL)
	{
		if (frctl->cmplx != NULL)
			free(frctl->cmplx);
		if (frctl->mlx != NULL)
			free(frctl->mlx);
		if (frctl->mtrx != NULL)
			free(frctl->mtrx);
		free(frctl);
	}
	ft_putstr_fd(str, 1);
	exit(1);
}

static int connect_init(t_connect *connect)
{
	connect->connect = mlx_init();
	if (!(connect->connect))
		return(1);
	connect->mlx_win = mlx_new_window(connect->connect, WD, HG, "fractol");
	if (!(connect->mlx_win))
		return(1);
	connect->img = mlx_new_image(connect->connect, WD, HG);
	if (!(connect->img))
		return(1);
	connect->addr = (int *)mlx_get_data_addr(connect->img,&connect->bites_per_px,&connect->line_length, &connect->endian);
	if (!(connect->addr))
		return (1);
	return (0);
}

void ft_malloc_fr(t_frctl *frctl)
{
	frctl->mlx = (t_connect*)malloc(sizeof(t_connect));
	if (!frctl->mlx)
		ft_puterror("error!", frctl);
	frctl->mtrx = (t_mtrx*)malloc(sizeof(t_frctl));
	if (!frctl->mtrx)
		ft_puterror("error!", frctl);
	frctl->cmplx = (t_cmplx*)malloc(sizeof(t_cmplx));
	if (!frctl->cmplx)
		ft_puterror("error!", frctl);
}

int	ft_put_fr_towin(t_frctl *frctl)
{
	if (frctl->mtrx->flag == 'm')
		mandelbro_dr(frctl);
	if (frctl->mtrx->flag == 'j')
		julia_dr(frctl);
	if (frctl->mtrx->flag == 's')
		serpinskiy_dr(frctl);
	mlx_put_image_to_window(frctl->mlx->connect, frctl->mlx->mlx_win, frctl->mlx->img, 0, 0);
}

int main(int ac, char **argv)
{
	t_frctl *frctl;

	frctl = NULL;
	if (ac == 2)
	{
		frctl = (t_frctl*)malloc(sizeof(t_frctl));
		if (!frctl)
			return (0);
		ft_malloc_fr(frctl);
		connect_init(frctl->mlx);
		if (ft_strcmp("mandelbrot", argv[1]) == 0)
			mandelbrot(frctl);
		else if (ft_strcmp("julia", argv[1]) == 0)
			julia(frctl);
		else if (ft_strcmp("serpinskiy", argv[1]) == 0)
			serpinskiy(frctl);
		else
			ft_puterror("You must choose: mandelbrot, julia, serpinskiy",
						frctl);
		ft_hook(frctl);
		mlx_put_image_to_window(frctl->mlx->connect, frctl->mlx->mlx_win, frctl->mlx->img, 0, 0);
		mlx_loop(frctl->mlx->connect);
	}
	else
		ft_puterror("You must choose: mandelbrot, julia, serpinskiy", frctl);
	return 0;
}

