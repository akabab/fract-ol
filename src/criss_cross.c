#include "fract.h"

int			hue_to_color(int hue)
{
	int		color;
	int		i;

	hue %= 360;
	i = 0;
	color = 0x000000;
	while (i != hue)
	{
		if (i < 60)
			color += 0x000400;
		else if (i < 120)
			color -= 0x040000;
		else if (i < 180)
			color += 0x000004;
		else if (i < 240)
			color -= 0x000400;
		else if (i < 300)
			color += 0x040000;
		else
			color -= 0x000004;
		i++;
	}
	return (color);
}

static int		burning_ship(int i)
{
	int		color;

	color = 0x000000;
	while (i != 0)
	{
		color += 0x010000;
		i--;
	}
	return (color);
}

int			fractal_ark(int x, int y, t_env *e)
{
	int		i;
	double	cp;
	t_z		z;
	t_z		const_z;

	const_z.a = z_xtoa(x, e);
	const_z.bi = z_ytobi(y, e) * -1;
	z.a = ft_abs_double(const_z.a);
	z.bi = ft_abs_double(const_z.bi);
	i = 0;
	while ((z.a * z.a + z.bi * z.bi) <= 4 && i < MAX_ITER)
	{
		cp = z.a;
		z.a = ft_abs_double(z.a) * ft_abs_double(z.a)
			- ft_abs_double(z.bi) * ft_abs_double(z.bi) + const_z.a;
		z.bi = 2 * ft_abs_double(cp) * ft_abs_double(z.bi) + const_z.bi;
		i++;
	}
	return (burning_ship(i * 2));
}

int			fractal_julia(int x, int y, t_env *e)
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

int			fractal_mandelbrotB(int x, int y, t_env *e, t_z c)
{
	int		i;
	double	cp;
	t_z		z;

	z.a = z_xtoa(x, e);
	z.bi = z_ytobi(y, e);
	i = 0;
	while ((z.a * z.a + z.bi * z.bi) <= 4 && i < 50)
	{
		cp = z.a;
		z.a = z.a * z.a - z.bi * z.bi + c.a;
		z.bi = 2 * cp * z.bi + c.bi;
		i++;
	}
	return ((i));
}

int			fractal_bouddha(int x, int y, t_env *e)
{
	double		i;
	double		j;
	t_z		c;
	int		color;

	color = 0;
	i = -2;
	while (i < 2)
	{
		j = -1;
		while (j < 1)
		{
//			c.a = z_xtoa(i, e);
//			c.bi = z_ytobi(j, e);
			c.a = i;
			c.bi = j;
			if (fractal_mandelbrotB(x, y, e, c) == 50)
				color += 1;
			j += 0.0234;
		}
		i += 0.0234;
	}
//	return (color);
	return (e->palette[e->start + ((color * e->step) % e->range)]);
}

int			fractal_mandelbrot(int x, int y, t_env *e)
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
	while ((z.a * z.a + z.bi * z.bi) <= 4 && i < MAX_ITER)
	{
		cp = z.a;
		z.a = z.a * z.a - z.bi * z.bi + const_z.a;
		z.bi = 2 * cp * z.bi + const_z.bi;
		i++;
	}
	if (i == MAX_ITER)
		return (0x000000);
	return (e->palette[e->start + ((i * e->step) % e->range)]);
}

void		criss_cross(t_env *e)
{
	int			x;
	int			y;
	int			color;

	x = 0;
	while (x != W_WIDTH)
	{
		y = 0;
		while (y != W_HEIGHT)
		{
			color = e->fract(x, y, e);
			my_pixel_put_to_image(e->img, x, y, color);
			y++;
		}
		x++;
	}
}
