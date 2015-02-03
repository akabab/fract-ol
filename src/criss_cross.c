#include "fract.h"

int			hue_to_color(int hue)
{
	int		color;
	int		i;

	hue %= 360;
	i = 0;
	color = 0x000000; //0xFF0000;
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

int			fractal_newton(int x, int y, t_env *e)
{
	int		color;

	(void)x;
	(void)y;
	(void)e;
	color = 0x000000;
	return (color);
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
	if (i == 0)
		return (0x000000);
	return (e->palette[e->start + ((i * e->step) % e->range)]);
	// return (hue_to_color(i * 2));
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
	return (hue_to_color(i * 2));
}

void		criss_cross(t_env *e, int (*f_fract)(int, int, t_env *))
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
			color = f_fract(x, y, e);
			my_pixel_put_to_image(e->img, x, y, color);
			y++;
		}
		x++;
	}
}
