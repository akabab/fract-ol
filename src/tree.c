#include "fract.h"

static void		branch(int deep, t_z pt1, t_z pt2, t_env *e)
{
	t_coord		pt3;
	t_coord		pt4;

	if (deep == 0)
		return;
	pt3.x = atox(pt1.a, e);
	pt3.y = bitoy(pt1.bi, e);
	pt4.x = atox(pt2.a, e);
	pt4.y = bitoy(pt2.bi, e);
	write(1, "321", 3);
	draw_line(0x004400, &pt3, &pt4, e->img);
	deep--;

/*	t_z		pt_A;
	t_z		pt_B;
	t_z		pt_C;
	double	lenght;*/

}

void			tree(t_env *e)
{
	int		deep;
	t_z		pt1;
	t_z		pt2;

	printf("test");
	pt1.a = 0;
	pt1.bi = 0;
	pt2.a = 0;
	pt2.bi = 2;
	e->origin->bi = +2;
	deep = 3;
	branch(deep, pt1, pt2, e);
}
