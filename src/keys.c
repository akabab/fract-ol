#include "fract.h"

int		key_release(int keycode, t_env *e)
{
	if (keycode == KEY_RIGHT)
		e->keys->right = FALSE;
	if (keycode == KEY_LEFT)
		e->keys->left = FALSE;
	if (keycode == KEY_UP)
		e->keys->up = FALSE;
	if (keycode == KEY_DOWN)
		e->keys->down = FALSE;
	if (keycode == KEY_ESC)
	{
		free_env(e);
		exit(0);
	}
	if (keycode == KEY_MORE)
		e->zoom *= ZOOM_IN_FACTOR;
	if (keycode == KEY_LESS)
		e->zoom *= ZOOM_OUT_FACTOR;
	if (keycode == KEY_RESET)
		init_params(e);
	if (keycode == KEY_SPACE)
	{
		printf("\n******************\n");
		printf("c = %f, %fi\n", e->c->a, e->c->bi);
		printf("zoom = %f\n", e->zoom);
		printf("origine = %f, %f\n", e->origin->a, e->origin->bi);
		printf("******************\n");
	}

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
	// printf("Key (released) code: [%d]\n", keycode);
	return (0);
}

int		key_press(int keycode, t_env *e)
{
	if (keycode == KEY_RIGHT)
		e->keys->right = TRUE;
	if (keycode == KEY_LEFT)
		e->keys->left = TRUE;
	if (keycode == KEY_UP)
		e->keys->up = TRUE;
	if (keycode == KEY_DOWN)
		e->keys->down = TRUE;
	printf("Key (pressed) code: [%d]\n", keycode);
	return (0);
}

void	manage_keys(t_env *e)
{
	if (e->keys->up == TRUE)
		e->origin->bi += RANGE_ORIGIN * e->zoom;
	if (e->keys->down == TRUE)
		e->origin->bi -= RANGE_ORIGIN * e->zoom;
	if (e->keys->right == TRUE)
		e->origin->a += RANGE_ORIGIN * e->zoom;
	if (e->keys->left == TRUE)
		e->origin->a -= RANGE_ORIGIN * e->zoom;
}

t_keys	*init_keys(void)
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
