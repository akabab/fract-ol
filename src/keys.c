/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 12:44:42 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/30 11:53:36 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

#define RANGE_C			0.02
#define RANGE_ORIGIN	10

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
		exit(0);

	/* tmp */
	if (keycode == KEY_A)
		e->origin->x -= RANGE_ORIGIN;
	if (keycode == KEY_D)
		e->origin->x += RANGE_ORIGIN;
	if (keycode == KEY_W)
		e->origin->y += RANGE_ORIGIN;
	if (keycode == KEY_S)
		e->origin->y -= RANGE_ORIGIN;
	if (keycode == KEY_MORE)
		e->zoom *= 2;
	if (keycode == KEY_LESS)
		e->zoom /= 2;
	if (keycode == KEY_SPACE)
	{
		printf("\n******************\n");
		printf("c = %f, %fi\n", e->c->x, e->c->y);
		printf("zoom = %f\n", e->zoom);
		printf("origine = %f, %f\n", e->origin->x, e->origin->y);
		printf("******************\n");
	}
	printf("Key (released) code: [%d]\n", keycode);
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
	// if (keycode == KEY_SHIFT)
	// if (keycode == KEY_MORE)
	// if (keycode == KEY_LESS)
	printf("Key (pressed) code: [%d]\n", keycode);
	return (0);
}

void	manage_keys(t_env *e)
{
	if (e->keys->up == TRUE)
		e->c->x += RANGE_C;
	if (e->keys->down == TRUE)
		e->c->x -= RANGE_C;
	if (e->keys->right == TRUE)
		e->c->y += RANGE_C;
	if (e->keys->left == TRUE)
		e->c->y -= RANGE_C;
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
