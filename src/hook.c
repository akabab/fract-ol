#include "fract.h"

int		pointer_motion_hook(int x, int y, t_env *e)
{
	e->c->a = Z_a(x, e);
	e->c->bi = Z_bi(y, e);
	//printf("Mouse at %d, %d\n", x, y);
	//printf("c-x = %f, c-y = %f\n", e->c->x, e->c->y);
	return (0);
}

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img->id, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	//useless -- overwritten by key_pressed & key_released
	(void)e;
	printf("Key (released) code: [%d]\n", keycode);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	double		a;
	double		bi;

	a = Z_a(x, e);
	bi = Z_bi(y, e);
	(void)a;
	(void)bi;

	double		new_a;
	double		new_bi;
	if (button == 4)
	{
		e->zoom *= 0.90;
		new_a = Z_a(x, e);
		new_bi = Z_bi(y, e);
		e->origin->a -= new_a - a;
		e->origin->bi -= new_bi - bi;
	}
	if (button == 5)
	{
		e->zoom *= 1.1;
		new_a = Z_a(x, e);
		new_bi = Z_bi(y, e);
		e->origin->a -= new_a - a;
		e->origin->bi -= new_bi - bi;
	}
	if (button == 3)
		displayHistogram();
	printf("Mouse code: [%d] at (%d, %d)\n", button, x, y);
	printf("point : (%fa, %fbi)\n", a, bi);
	printf("origine : (%fx, %fy)\n", e->origin->a, e->origin->bi);
	return (0);
}

int		loop_hook(t_env *e)
{
	manage_keys(e);
	criss_cross(e, &fractal_julia);
	mlx_put_image_to_window(e->mlx, e->win, e->img->id, 0, 0);
	return (0);
}