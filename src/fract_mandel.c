#include "fract.h"

static int	fractal_mandelbrot3(int x, int y, t_env *e)
{
	int		i;
	double	cp;
	t_z		z;
	t_z		const_z;

	z.a = z_xtoa(x, e);
	z.bi = z_ytobi(y, e);
	const_z.a = z.a;
	const_z.bi = z.bi;
	i = 0;
	while ((d_power(z.a, 2) + d_power(z.bi, 2)) <= 4 && i < MAX_ITER)
	{
		cp = z.a;
		z.a = d_power(z.a, 4) - 6 * d_power(z.a, 2) * d_power(z.bi, 2)
			+ d_power(z.bi, 4) + const_z.a;
		z.bi = 4 * d_power(cp, 3) * z.bi
			- 4 * cp * d_power(z.bi, 3) + const_z.bi;
		i++;
	}
	if (i == MAX_ITER)
		return (0x000000);
	return (get_palette_color(e->col, i));
}

static int	fractal_mandelbrot2(int x, int y, t_env *e)
{
	int		i;
	double	cp;
	t_z		z;
	t_z		const_z;

	z.a = z_xtoa(x, e);
	z.bi = z_ytobi(y, e);
	const_z.a = z.a;
	const_z.bi = z.bi;
	i = 0;
	while ((d_power(z.a, 2) + d_power(z.bi, 2)) <= 4 && i < MAX_ITER)
	{
		cp = z.a;
		z.a = d_power(z.a, 3) - 3 * z.a * d_power(z.bi, 2) + const_z.a;
		z.bi = 3 * d_power(cp, 2) * z.bi - d_power(z.bi, 3) + const_z.bi;
		i++;
	}
	if (i == MAX_ITER)
		return (0x000000);
	return (get_palette_color(e->col, i));
}

static int	fractal_mandelbrot1(int x, int y, t_env *e)
{
	int		i;
	double	cp;
	t_z		z;
	t_z		const_z;

	z.a = z_xtoa(x, e);
	z.bi = z_ytobi(y, e);
	const_z.a = z.a;
	const_z.bi = z.bi;
	i = 0;
	while ((d_power(z.a, 2) + d_power(z.bi, 2)) <= 4 && i < MAX_ITER)
	{
		cp = z.a;
		z.a = d_power(z.a, 2) - z.bi * z.bi + const_z.a;
		z.bi = 2 * cp * z.bi + const_z.bi;
		i++;
	}
	if (i == MAX_ITER)
		return (0x000000);
	return (get_palette_color(e->col, i));
}

int			fractal_mandelbrot(int x, int y, t_env *e)
{
	if (e->power == 1)
		return (fractal_mandelbrot1(x, y, e));
	else if (e->power == 2)
		return (fractal_mandelbrot2(x, y, e));
	else if (e->power == 3)
		return (fractal_mandelbrot3(x, y, e));
	else
		return (0x000000);
}

void		init_mandel(t_env *e)
{
	e->origin->a = MANDEL_ORIGIN_A;
	e->origin->bi = MANDEL_ORIGIN_BI;
	e->zoom = MANDEL_ZOOM;
	e->power = MANDEL_POWER;
	e->col->col1 = MANDEL_COL1;
	e->col->col2 = MANDEL_COL2;
}
