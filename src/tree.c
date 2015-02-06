#include "fract.h"

static void		branch(int deep, t_z start, t_z next, t_env *e);

static void		leaf(int deep, t_z start, t_z next, t_env *e)
{
	double		lenght;
	t_z			pt;

	lenght = ft_abs_double(start.a - next.a) > ft_abs_double(start.bi - next.bi)
		? ft_abs_double(start.a - next.a) : ft_abs_double(start.bi - next.bi);
	lenght *= 2./5;
	if (start.bi == next.bi)
	{
		pt.a = (start.a > next.a) ? next.a - lenght : next.a + lenght;
		pt.bi = next.bi;
		branch(deep, next, pt, e);
		pt.a = next.a;
		pt.bi = next.bi + lenght;
		branch(deep, next, pt, e);
		pt.bi = next.bi - lenght;
		branch(deep, next, pt, e);
	}
	if (start.a == next.a)
	{
		pt.a = next.a;
		pt.bi = (start.bi > next.bi) ? next.bi - lenght : next.bi + lenght;
		branch(deep, next, pt, e);
		pt.bi = next.bi;
		pt.a = next.a + lenght;
		branch(deep, next, pt, e);
		pt.a = next.a - lenght;
		branch(deep, next, pt, e);
	}
}

static void		branch(int deep, t_z start, t_z next, t_env *e)
{
	t_coord		first;
	t_coord		second;
	int			color;
	int			i;

	if (deep > (int)((e->c->bi - 1.) * 5) || deep > 10)
		return;
	color = 0xaa5500;
	i = 0;
	while (i != deep)
	{
		color -= 0x110000;
		i++;
	}
	first.x = atox(start.a, e);
	first.y = bitoy(start.bi, e);
	second.x = atox(next.a, e);
	second.y = bitoy(next.bi, e);
	draw_line(color, &first, &second, e->img);
	deep++;
	leaf(deep, start, next, e);
}

static void		clean(t_env *e)
{
	int		i;
	int		j;
	int		color;

	color = 0x000000;
	i = 0;
	while (i != W_WIDTH)
	{
		j = 0;
		while (j != W_HEIGHT)
		{
			my_pixel_put_to_image(e->img, i, j, color);
			j++;
		}
		i++;
	}
}


void			tree(t_env *e)
{
	int		deep;
	t_z		start;
	t_z		next;

	deep = 0;
	clean(e);
	start.a = 0;
	start.bi = 0;
	next.a = 0;
	next.bi = 2.;
	deep = 0;
	branch(deep, start, next, e);
	start.a = 1;
	next.a = start.a;
	start.bi = 0;
	next.bi = 0.75;
	branch(deep, start, next, e);
	start.a = -1;
	next.a = start.a;
	branch(deep, start, next, e);
}
