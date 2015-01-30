/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 11:30:55 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/30 11:48:45 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		pointer_motion_hook(int x, int y, t_env *e)
{
	(void)e;
	printf("Mouse at %d, %d\n", x, y);
	return (0);
}

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img->id, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	(void)e;
	printf("Key (released) code: [%d]\n", keycode);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	(void)e;
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
