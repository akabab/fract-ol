#include "fract.h"

int			fractal_julia(int x, int y, t_env *e)
{
	int		color;
	int		i;
	double	a;
	double	bi;
	double	cp;

	a = Z_a(x, e);
	bi = Z_bi(y, e);
	i = 0;
	color = 0xeeeeee;
	while ((a * a + bi * bi) <= 4 && i < 256)
	{
		cp = a;
		a = a * a - bi * bi + e->c->a;
		bi = 2 * cp * bi + e->c->bi;
		color -= 0x020202;
		i++;
	}
	return (color);
}

void		criss_cross(t_env *e, int (*ft)(int, int, t_env *))
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
			color = ft(x, y, e);
			my_pixel_put_to_image(e->img, x, y, color);
			y++;
		}
		x++;
	}
}


