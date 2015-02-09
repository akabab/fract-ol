#include "fract.h"

static int	fractal_julia3(int x, int y, t_env *e)
{
	int		i;
	double	cp;
	t_z		z;

	z.a = z_xtoa(x, e);
	z.bi = z_ytobi(y, e);
	i = 0;
	while ((d_power(z.a, 2) + d_power(z.bi, 2)) <= 4 && i < MAX_ITER)
	{
		cp = z.a;
		z.a = d_power(z.a, 4) - 6 * d_power(z.a, 2) * d_power(z.bi, 2)
			+ d_power(z.bi, 4) + e->c->a;
		z.bi = 4 * d_power(cp, 3) * z.bi
			- 4 * cp * d_power(z.bi, 3) + e->c->bi;
		i++;
	}
	if (i == MAX_ITER)
		return (0x000000);
	return (get_palette_color(e->col, i));
}

static int	fractal_julia2(int x, int y, t_env *e)
{
	int		i;
	double	cp;
	t_z		z;

	z.a = z_xtoa(x, e);
	z.bi = z_ytobi(y, e);
	i = 0;
	while ((d_power(z.a, 2) + d_power(z.bi, 2)) <= 4 && i < MAX_ITER)
	{
		cp = z.a;
		z.a = d_power(z.a, 3) - 3 * z.a * d_power(z.bi, 2) + e->c->a;
		z.bi = 3 * d_power(cp, 2) * z.bi - d_power(z.bi, 3) + e->c->bi;
		i++;
	}
	if (i == MAX_ITER)
		return (0x000000);
	return (get_palette_color(e->col, i));
}

static int	fractal_julia1(int x, int y, t_env *e)
{
	int		i;
	t_z		z;
	double	cp;

	z.a = z_xtoa(x, e);
	z.bi = z_ytobi(y, e);
	i = 0;
	while ((z.a * z.a + z.bi * z.bi) <= 4 && i < MAX_ITER)
	{
		cp = z.a;
		z.a = z.a * z.a - z.bi * z.bi + e->c->a;
		z.bi = 2 * cp * z.bi + e->c->bi;
		i++;
	}
	if (i == MAX_ITER)
		return (0x000000);
	return (get_palette_color(e->col, i));
}

int			fractal_julia(int x, int y, t_env *e)
{
	if (e->power == 1)
		return (fractal_julia1(x, y, e));
	if (e->power == 2)
		return (fractal_julia2(x, y, e));
	if (e->power == 3)
		return (fractal_julia3(x, y, e));
	else
		return (0x000000);
}

void		init_julia(t_env *e)
{
	e->c->a = JULIA_A;
	e->c->bi = JULIA_BI;
	e->origin->a = JULIA_ORIGIN_A;
	e->origin->bi = JULIA_ORIGIN_BI;
	e->zoom = JULIA_ZOOM;
	e->power = JULIA_POWER;
	e->col->col1 = JULIA_COL1;
	e->col->col2 = JULIA_COL2;
}
