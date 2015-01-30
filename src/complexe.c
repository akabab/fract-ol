
#include "fract.h"

t_Z		*coord_to_z(int x, int y, t_env *e)
{
	t_Z		*z;
	double	size;

	z = malloc(sizeof(t_Z));
	size = 4. / W_WIDTH * e->zoom;
	z->a = (double)x * size - (W_WIDTH / 2) * size + e->origin->a;
	z->bi = (W_HEIGHT / 2) * size - (double)y * size + e->origin->bi;
	return (z);
}

double		Z_a(int x, t_env *e)
{
	double	size;

	size = 4. / W_WIDTH * e->zoom;
	return ((double)x * size - (W_WIDTH / 2) * size + e->origin->a);
}

double		Z_bi(int y, t_env *e)
{
	double	size;

	size = 4. / W_WIDTH * e->zoom;
	return ((W_HEIGHT / 2) * size - (double)y * size + e->origin->bi);
}
