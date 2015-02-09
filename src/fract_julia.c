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
	return (e->palette[e->start + ((i * e->step) % e->range)]);
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
	return (e->palette[e->start + ((i * e->step) % e->range)]);
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
	return (e->palette[e->start + ((i * e->step) % e->range)]);
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

int			init_julia(t_env *e)
{
	e->power = 1;
	e->c->a = 0.0;
	e->c->bi = 0.0;
	e->origin->a = 0;
	e->origin->bi = 0;
	e->zoom = 1.0;
	e->show_palette = TRUE;
	return (0x4169E1);
}
