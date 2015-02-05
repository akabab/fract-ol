#include "fract.h"

t_z			*coord_to_z(int x, int y, t_env *e)
{
	t_z		*z;
	double	size;

	z = malloc(sizeof(t_z));
	size = 4. / W_WIDTH * e->zoom;
	z->a = (double)x * size - (W_WIDTH / 2) * size + e->origin->a;
	z->bi = (W_HEIGHT / 2) * size - (double)y * size + e->origin->bi;
	return (z);
}

double		z_xtoa(int x, t_env *e)
{
	double	size;

	size = 4. / W_WIDTH * e->zoom;
	return ((double)x * size - (W_WIDTH / 2) * size + e->origin->a);
}

double		z_ytobi(int y, t_env *e)
{
	double	size;

	size = 4. / W_WIDTH * e->zoom;
	return ((W_HEIGHT / 2) * size - (double)y * size + e->origin->bi);
}

int			atox(double a, t_env *e)
{
	int		x;
	double	size;

	size = 4. / W_WIDTH * e->zoom;
	x = (int)(((W_WIDTH / 2) * size - e->origin->a + a) / size);
	return (x);
}

int			bitoy(double bi, t_env *e)
{
	int		y;
	double	size;

	size = 4. / W_WIDTH * e->zoom;
	y = (int)(((W_HEIGHT / 2) * size - bi + e->origin->bi) / size);
	return (y);
}
