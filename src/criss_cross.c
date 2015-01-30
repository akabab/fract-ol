#include "fract.h"

int			fractal_julia(int x, int y, t_env *e)
{
	int		color;
	double	coord_x;
	double	coord_y;
	double	a;
	double	b;
	int		i;

	color = 0xeeeeee;
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


