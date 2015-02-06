#include "fract.h"

void			free_env(t_env *e)
{
	free(e->keys);
	free(e->c);
	free(e->origin);
	free(e);
}

static t_img	*create_new_image(t_env *e, int width, int height)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	if (!(img->id = mlx_new_image(e->mlx, width, height)))
		return (NULL);
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr(img->id, &img->bpp,
			&img->lsize, &img->endian);
	return (img);
}

void			init_params(t_env *e)
{
	if (ft_strequ(e->title, "mandel"))
	{
		e->origin->a = MANDEL_ORIGIN_A;
		e->origin->bi = MANDEL_ORIGIN_BI;
		e->zoom = MANDEL_ZOOM;
	}
	else if (ft_strequ(e->title, "ark"))
	{
		e->origin->a = ARK_ORIGIN_A;
		e->origin->bi = ARK_ORIGIN_BI;
		e->zoom = ARK_ZOOM;
	}
	else
	{
		e->c->a = 0.0;
		e->c->bi = 0.0;
		e->origin->a = 0;
		e->origin->bi = 0;
		if (ft_strequ(e->title, "tree"))
			e->origin->bi = 2;
		e->zoom = 1.0;
	}
	e->step = 1;
	e->start = 0;
	e->range = PALETTE_SIZE - 1;
}

t_env			*init_env(char *title)
{
	t_env	*e;

	t_color	c1 = hexToRgb(0x0D70C6);
	t_color	c2 = hexToRgb(0xDBAB00);

	if (!(e = malloc(sizeof(t_env))))
		exit(-1);
	if (!(e->mlx = mlx_init()))
		exit(-1);
	if (!(e->win = mlx_new_window(e->mlx, W_WIDTH, W_HEIGHT, title)))
		exit(-1);
	if (!(e->img = create_new_image(e, W_WIDTH, W_HEIGHT)))
		exit(-1);
	if (!(e->keys = init_keys()))
		exit(-1);
	if (!(e->c = malloc(sizeof(t_z))))
		exit(-1);
	if (!(e->origin = malloc(sizeof(t_z))))
		exit(-1);
	if (!(e->palette = generate_bw_gradient_palette(c1, c2, PALETTE_SIZE)))
		exit(-1);
	e->title = title;
	init_params(e);
	return (e);
}
