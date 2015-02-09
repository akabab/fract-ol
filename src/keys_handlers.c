#include "fract.h"
#include "keys.h"

void		keys_power_handler(int keycode, t_env *e)
{
	if (keycode == KEY_1)
		e->power = 1;
	if (keycode == KEY_2)
		e->power = 2;
	if (keycode == KEY_3)
		e->power = 3;
}

void		keys_zoom_handler(int keycode, t_env *e)
{
	if (keycode == KEY_MORE)
		e->zoom *= ZOOM_IN_FACTOR;
	if (keycode == KEY_LESS)
		e->zoom *= ZOOM_OUT_FACTOR;
}

void		keys_arrows_handler(int keycode, t_env *e)
{
	if (keycode == KEY_RIGHT)
		e->keys->right = FALSE;
	if (keycode == KEY_LEFT)
		e->keys->left = FALSE;
	if (keycode == KEY_UP)
		e->keys->up = FALSE;
	if (keycode == KEY_DOWN)
		e->keys->down = FALSE;
}

void		keys_color_handler(int keycode, t_env *e)
{
	if (keycode == 45)
		e->start--;
	if (keycode == 61)
		e->start++;
	if (keycode == 91)
		e->range--;
	if (keycode == 93)
		e->range++;
	if (keycode == 57)
		e->step--;
	if (keycode == 48)
		e->step++;
}
