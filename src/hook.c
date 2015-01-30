#include "fract.h"

int		pointer_motion_hook(int x, int y, t_env *e)
{
	e->c->x = (double)x / (W_WIDTH);
	e->c->y = (double)y / (W_HEIGHT);
	printf("Mouse at %d, %d\n", x, y);
	printf("c-x = %f, c-y = %f\n", e->c->x, e->c->y);
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
	if (button == 4)
		e->zoom /= 2;
	if (button == 5)
		e->zoom *= 2;
	printf("Mouse code: [%d] at (%d, %d)\n", button, x, y);
	return (0);
}

int		loop_hook(t_env *e)
{
	manage_keys(e);
	criss_cross(e, &fractal_julia);
	mlx_put_image_to_window(e->mlx, e->win, e->img->id, 0, 0);
	return (0);
}
