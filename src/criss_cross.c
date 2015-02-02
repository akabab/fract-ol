#include "fract.h"

int			hue_to_color(int hue)
{
	int		color;
	int		i;

	hue = hue % 360;
	i = 0;
	color = 0xff0000;
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

	color = 0xff0000;
	return (color);
}

int			fractal_julia(int x, int y, t_env *e)
{
	int		i;
	double	a;
	double	bi;
	double	cp;

	a = Z_a(x, e);
	bi = Z_bi(y, e);
	i = 0;
	while ((a * a + bi * bi) <= 4 && i < 180)
	{
		cp = a;
		a = a * a - bi * bi + e->c->a;
		bi = 2 * cp * bi + e->c->bi;
		i++;
	}
	return (hue_to_color(i * 2));
}

int			fractal_mandelbrot(int x, int y, t_env *e)
{
	int		i;
	double	a;
	double	bi;
	double	cp;
	double	const_a;
	double	const_bi;

	a = Z_a(x, e);
	bi = Z_bi(y, e);
	const_a = a;
	const_bi = bi;
	i = 0;
	while ((a * a + bi * bi) <= 4 && i < 180)
	{
		cp = a;
		a = a * a - bi * bi + const_a;
		bi = 2 * cp * bi + const_bi;
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


