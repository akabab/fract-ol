#include "fract.h"

extern t_fract g_fract;

typedef struct	s_color
{
	float	r;
	float	g;
	float	b;
}				t_color;

int		rgbToHex(float r, float g, float b)
{
	int		hexColor;

	r = r > 1.0 ? 1.0 : r;
	r = r < 0.0 ? 0.0 : r;
	g = g > 1.0 ? 1.0 : g;
	g = g < 0.0 ? 0.0 : g;
	b = b > 1.0 ? 1.0 : b;
	b = b < 0.0 ? 0.0 : b;
	hexColor = 0x000000;

	hexColor += (int)(r * 0xFF) << 16;
	hexColor += (int)(g * 0xFF) << 8;
	hexColor += (int)(b * 0xFF);
	return (hexColor);
}

void		clearHistogram()
{
	int	i;

	i = 0;
	while (i < N_ITER)
	{
		g_fract.histogram[i] = 0;
		i++;
	}
}

void		displayHistogram()
{
	int	i;

	i = 0;
	while (i < N_ITER)
	{
		printf("[%d] - %d\n", i, g_fract.histogram[i]);
		i++;
	}
}

int			fractal_julia(int x, int y, t_env *e)
{
	int		color;
	int		i;
	double	a;
	double	bi;
	double	cp;

	t_color	col;
	col.r = 1.0;
	col.g = 1.0;
	col.b = 1.0;
	color = rgbToHex(col.r, col.g, col.b);

	a = Z_a(x, e);
	bi = Z_bi(y, e);
	i = 0;
	while ((a * a + bi * bi) <= 4 && i < 256)
	{
		cp = a;
		a = a * a - bi * bi + e->c->a;
		bi = 2 * cp * bi + e->c->bi;
		i++;
	}
	g_fract.histogram[i]++;
	col.r = (float)(i % 5) / 5;
	col.b = (float)(i % 30) / 30;
	color = rgbToHex(1.0 - col.r, 0.0, 1.0 - col.b);
	return (color);
}

int			fractal_mandelbrot(int x, int y, t_env *e)
{
	int		color;
	int		i;
	double	a;
	double	bi;
	double	cp;
	double	const_a;
	double	const_bi;

	t_color	col;
	col.r = 1.0;
	col.g = 1.0;
	col.b = 1.0;
	color = rgbToHex(col.r, col.g, col.b);

	a = Z_a(x, e);
	bi = Z_bi(y, e);
	const_a = a;
	const_bi = bi;
	i = 0;
	while ((a * a + bi * bi) <= 4 && i < 256)
	{
		cp = a;
		a = a * a - bi * bi + const_a;
		bi = 2 * cp * bi + const_bi;
		i++;
	}
	g_fract.histogram[i]++;
	col.r = (float)(i % 5) / 5;
	col.b = (float)(i % 30) / 30;
	color = rgbToHex(1.0 - col.r, 0.0, 1.0 - col.b);
	return (color);
}

void		criss_cross(t_env *e, int (*ft)(int, int, t_env *))
{
	int			x;
	int			y;
	int			color;

	clearHistogram();
	x = 0;
	while (x != W_WIDTH)
	{
		y = 0;
		while (y != W_HEIGHT)
		{
			color = ft(x, y, e);
			my_pixel_put_to_image(e->img, x, y, color);
			y++;
		}
		x++;
	}
}


