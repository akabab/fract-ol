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
	t_color	c1;
	t_color	c2;
	int		color;

	color = 0x000000;
	if (ft_strequ(e->title, "mandel"))
		color = init_mandel(e);
	else if (ft_strequ(e->title, "ark"))
		init_ark(e);
	else if (ft_strequ(e->title, "julia"))
		color = init_julia(e);
	else if (ft_strequ(e->title, "tree"))
		init_tree(e);
	c1 = hexToRgb(color);
	c2 = hexToRgb((0xFFFFFF - color));
	if (!(e->palette = generate_bw_gradient_palette(c1, c2, PALETTE_SIZE)))
		exit(-1);
	e->step = 1;
	e->start = 0;
	e->range = PALETTE_SIZE - 1;
}

t_env			*init_env(char *title)
{
	t_env	*e;
	int		color;

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
	e->title = title;
	init_params(e);
	return (e);
}
