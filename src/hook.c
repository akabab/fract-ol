#include "fract.h"

int				pointer_motion_hook(int x, int y, t_env *e)
{
	e->c->a = z_xtoa(x, e);
	e->c->bi = z_ytobi(y, e);
	// printf("Mouse at %d, %d\n", x, y);
	// printf("c-x = %f, c-y = %f\n", e->c->x, e->c->y);
	return (0);
}

int				expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img->id, 0, 0);
	return (0);
}

int				key_hook(int keycode, t_env *e)
{
	// useless -- overwritten by key_pressed & key_released
	(void)e;
	printf("Key (released) code: [%d]\n", keycode);
	return (0);
}

static void		zoom(int x, int y, float zoom_factor, t_env *e)
{
	t_z		z;
	t_z		new_z;

	z.a = z_xtoa(x, e);
	z.bi = z_ytobi(y, e);
	e->zoom *= zoom_factor;
	new_z.a = z_xtoa(x, e);
	new_z.bi = z_ytobi(y, e);
	e->origin->a -= new_z.a - z.a;
	e->origin->bi -= new_z.bi - z.bi;
	// printf("point : (%fa, %fbi)\n", a, bi);
	// printf("origine : (%fx, %fy)\n", e->origin->a, e->origin->bi);
}

int				mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == SCROLL_UP)
		zoom(x, y, ZOOM_IN_FACTOR, e);
	if (button == SCROLL_DOWN)
		zoom(x, y, ZOOM_OUT_FACTOR, e);
	// printf("Mouse code: [%d] at (%d, %d)\n", button, x, y);
	return (0);
}
