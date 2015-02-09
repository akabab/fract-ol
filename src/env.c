#include "fract.h"

void			free_env(t_env *e)
{
	free(e->keys);
	free(e->col->palette);
	free(e->col);
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

static void		init_col_palette(t_env *e)
{
	t_color		c1;
	t_color		c2;

	c1 = hex_to_rgb(e->col->col1);
	c2 = hex_to_rgb(e->col->col2);
	if (!(e->col->palette = gen_bw_gradient_palette(c1, c2, PALETTE_SIZE)))
		exit(-1);
	e->col->step = 1;
	e->col->start = 0;
	e->col->range = PALETTE_SIZE - 1;
	e->col->is_visible = FALSE;
}

void			init_params(t_env *e)
{
	if (ft_strequ(e->title, "mandel"))
		init_mandel(e);
	else if (ft_strequ(e->title, "ark"))
		init_ark(e);
	else if (ft_strequ(e->title, "julia"))
		init_julia(e);
	else if (ft_strequ(e->title, "tree"))
		init_tree(e);
}

t_env			*init_env(char *title)
{
	t_env	*e;

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
	if (!(e->col = malloc(sizeof(t_col_palette))))
		exit(-1);
	if (!(e->c = malloc(sizeof(t_z))))
		exit(-1);
	if (!(e->origin = malloc(sizeof(t_z))))
		exit(-1);
	e->title = title;
	init_params(e);
	init_col_palette(e);
	e->need_recompute = TRUE;
	e->multi_threads = TRUE;
	return (e);
}
