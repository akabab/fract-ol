/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 15:18:38 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/30 11:10:42 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int			loop_hook(t_env *e)
{
	manage_keys(e);
	criss_cross(e, &fractal_julia);
	mlx_put_image_to_window(e->mlx, e->win, e->img->id, 0, 0);
	return (0);
}

t_img		*create_new_image(t_env *e, int width, int height)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
		exit(-1);
	if (!(img->id = mlx_new_image(e->mlx, width, height)))
		exit(-1);
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr(img->id, &img->bpp,
			&img->lsize, &img->endian);
	return (img);
}

t_env		*init_env(void)
{
	t_env	*e;
	double	zoom;

	zoom = 1.0;
	if (!(e = malloc(sizeof(t_env))))
		exit(-1);
	if (!(e->mlx = mlx_init()))
		exit(-1);
	if (!(e->win = mlx_new_window(e->mlx, W_WIDTH, W_HEIGHT, "Fractal")))
		exit(-1);
	if (!(e->keys = init_keys()))
		exit(-1);
	if (!(e->c = malloc(sizeof(t_pt))))
		exit(-1);
	if (!(e->origin = malloc(sizeof(t_pt))))
		exit(-1);
	e->c->x = 0.0;
	e->c->y = 0.6;
	e->origin->x = 0.0;
	e->origin->y = 0.0;
	e->zoom = zoom;
	return (e);
}

int			main()
{
	t_env		*e;

	e = init_env();

	e->img = create_new_image(e, W_WIDTH, W_HEIGHT);
	mlx_hook(e->win, KeyPress, KeyPressMask, &key_press, e);
	mlx_hook(e->win, KeyRelease, KeyReleaseMask, &key_release, e);
	mlx_loop_hook(e->mlx, &loop_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
