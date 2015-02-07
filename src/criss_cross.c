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
