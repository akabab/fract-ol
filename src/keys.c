#include "fract.h"
#include "keys.h"

int			key_release(int keycode, t_env *e)
{
	keys_arrows_handler(keycode, e);
	keys_color_handler(keycode, e);
	keys_power_handler(keycode, e);
	keys_zoom_handler(keycode, e);
	if (keycode == KEY_RESET)
		init_params(e);
	if (keycode == KEY_T)
		e->multi_threads = !e->multi_threads;
	if (keycode == KEY_ESC)
	{
		free_env(e);
		exit(0);
	}
	e->need_recompute = TRUE;
	return (0);
}

int			key_press(int keycode, t_env *e)
{
	if (keycode == KEY_RIGHT)
		e->keys->right = TRUE;
	if (keycode == KEY_LEFT)
		e->keys->left = TRUE;
	if (keycode == KEY_UP)
		e->keys->up = TRUE;
	if (keycode == KEY_DOWN)
		e->keys->down = TRUE;
	return (0);
}

void		manage_keys(t_env *e)
{
	if (e->keys->up == TRUE)
	{
		e->origin->bi += RANGE_ORIGIN * e->zoom;
		e->need_recompute = TRUE;
	}
	if (e->keys->down == TRUE)
	{
		e->origin->bi -= RANGE_ORIGIN * e->zoom;
		e->need_recompute = TRUE;
	}
	if (e->keys->right == TRUE)
	{
		e->origin->a += RANGE_ORIGIN * e->zoom;
		e->need_recompute = TRUE;
	}
	if (e->keys->left == TRUE)
	{
		e->origin->a -= RANGE_ORIGIN * e->zoom;
		e->need_recompute = TRUE;
	}
}

t_keys		*init_keys(void)
{
	t_keys		*keys;

	keys = malloc(sizeof(keys));
	if (keys == NULL)
		exit(EXIT_FAILURE);
	keys->up = FALSE;
	keys->down = FALSE;
	keys->right = FALSE;
	keys->left = FALSE;
	return (keys);
}
