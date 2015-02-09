#include "fract.h"

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
