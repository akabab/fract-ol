#include "fract.h"

int			loop_hook(t_env *e)
{
	manage_keys(e);
	if (ft_strequ(e->title, "tree"))
		tree(e);
	else
		compute_fract(e);
		// criss_cross(e, e->fract);
	draw_palette(e->palette, PALETTE_SIZE, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img->id, 0, 0);
	return (0);
}

void		mlx_handler(t_env *e)
{
	mlx_expose_hook(e->win, &expose_hook, e);
	mlx_key_hook(e->win, &key_hook, e);
	mlx_mouse_hook(e->win, &mouse_hook, e);
	mlx_hook(e->win, KeyPress, KeyPressMask, &key_press, e);
	mlx_hook(e->win, KeyRelease, KeyReleaseMask, &key_release, e);
	mlx_hook(e->win, MotionNotify, PointerMotionMask, &pointer_motion_hook, e);
	mlx_loop_hook(e->mlx, &loop_hook, e);
	mlx_loop(e->mlx);
}
