/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:52:18 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/09 17:54:12 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void		*match_fractal(char *fractal)
{
	if (ft_strequ(fractal, "julia"))
		return (&fractal_julia);
	else if (ft_strequ(fractal, "mandel"))
		return (&fractal_mandelbrot);
	else if (ft_strequ(fractal, "ark"))
		return (&fractal_ark);
	else if (ft_strequ(fractal, "tree"))
		return (&tree);
	else
		ft_printf("fractal '%s' not found\n", fractal);
	return (NULL);
}

static void		wait_child(int pid)
{
	int		status;

	waitpid(pid, &status, 0);
}

static t_bool	is_child_process(int pid)
{
	return (pid == 0);
}

static void		load(char *fractal)
{
	t_env		*e;
	void		*ft_fract;

	if (!(ft_fract = match_fractal(fractal)))
		return ;
	ft_printf("> Loading '%s'..\n", fractal);
	e = init_env(fractal);
	e->fract = ft_fract;
	mlx_handler(e);
}

int				main(int ac, char *av[])
{
	int			pid;
	int			status;

	if (ac < 2)
		ft_printf("Usage: %s <fract {julia, mandel, ark, tree, ...}>\n", av[0]);
	else if (ac == 2)
		load(av[1]);
	else
	{
		int i = 1;
		while (i < ac)
		{
			pid = fork();
			if (is_child_process(pid))
				execv(av[0], (char *[]) { av[0], av[i], NULL });
			if (OPEN_IN_SERIES)
				wait_child(pid);
			i++;
		}
	}
	if (!OPEN_IN_SERIES)
		while ((pid = wait(&status)) > 0) {}
	return (0);
}
