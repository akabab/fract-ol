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
	double	coord_x;
	double	coord_y;
	double	a;
	double	b;
	int		i;

	t_color	col;
	col.r = 1.0;
	col.g = 1.0;
	col.b = 1.0;
	color = rgbToHex(col.r, col.g, col.b);
	coord_x = (((((double)x + 1) - (W_WIDTH / 2 + e->origin->x))
			/ (W_WIDTH / 2))) * e->zoom;
	coord_y = ((((((double)y + 1) - (W_HEIGHT / 2 - e->origin->y)) * -1)
			/ (W_HEIGHT / 2))) * e->zoom;
	i = 0;
	while ((coord_x * coord_x + coord_y * coord_y) <= 4 && i < 256)
	{
		a = coord_x * coord_x - coord_y * coord_y;
		b = 2 * coord_x * coord_y;
		coord_x = a + e->c->x;
		coord_y = b + e->c->y;
		i++;
	}
	g_fract.histogram[i]++;
	col.r = (float)(i % 5) / 5;
	col.b = (float)(i % 30) / 30;
	color = rgbToHex(1.0 - col.r, 0.0, 1.0 - col.b);
	// printf("%x\n", color);
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


