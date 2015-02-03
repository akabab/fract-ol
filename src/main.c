#include "fract.h"

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

static t_env	*init_env(char *title)
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
	if (!(e->c = malloc(sizeof(t_Z))))
		exit(-1);
	if (!(e->origin = malloc(sizeof(t_Z))))
		exit(-1);
	e->c->a = 0.0;
	e->c->bi = 0.0;
	e->origin->a = 0;
	e->origin->bi = 0;
	e->zoom = 1.0;
	return (e);
}

static void		*match_fractal(char *av)
{
	if (ft_strequ(av, "julia"))
		return (&fractal_julia);
	else if (ft_strequ(av, "mandel"))
		return (&fractal_mandelbrot);
	else if (ft_strequ(av, "newton"))
		return (&fractal_newton);
	else
	{
		ft_putstr(av);
		ft_putendl(" is invalid. Valids <fract> {julia, mandel, newton, ...}");
	}
	return (NULL);
}

static void		waitChild(int *pid)
{
	int		status;

	*pid = wait(&status);
}

int				main(int ac, char *av[])
{
	int			i;
	t_env		*e;
	void		*ft_fract;
	int			pid;

	i = 1;
	if (ac < 2)
		ft_putendl("Usage: ./fractol <fract> ... {julia, mandel, newton, ...}");
	while (i < ac)
	{
		if (ft_fract = match_fractal(av[i]))
		{
			if (!(pid = fork()))
			{
				e = init_env(av[i]);
				e->fract = ft_fract;
				mlx_handler(e);
			}
		}
		i++;
	}
	while (i-- > 1)
		waitChild(&pid);
	return (0);
}
