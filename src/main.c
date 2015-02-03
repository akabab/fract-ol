#include "fract.h"

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

static void		wait_child(int *pid)
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
		wait_child(&pid);
	return (0);
}
