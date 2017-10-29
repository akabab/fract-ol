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

static void		*match_fractal(char *av)
{
	if (ft_strequ(av, "julia"))
		return (&fractal_julia);
	else if (ft_strequ(av, "mandel"))
		return (&fractal_mandelbrot);
	else if (ft_strequ(av, "ark"))
		return (&fractal_ark);
	else if (ft_strequ(av, "tree"))
		return (&tree);
	else
		ft_printf("[%s] is invalid. <fract> {julia, mandel, ark, tree, ...}\n",
				av);
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
	e = init_env(fractal);
	e->fract = ft_fract;
	mlx_handler(e);
}

int				main(int ac, char *av[])
{
	char		*path;
	int			pid;
	int			status;

	path = av[0];
	if (ac < 2)
		ft_printf("Usage: %s <fract {julia, mandel, ark, tree, ...}>\n", path);
	else if (ac == 2) {
		printf(">> Loading.. '%s'\n", av[1]);
		load(av[1]);
	}
	else
	{
		int i = 1;
		while (i < ac)
		{
			pid = fork();
			if (is_child_process(pid)) {
				printf("(child) execv '%s'\n", av[i]);
				execv(path, (char *[]) { path, av[i], NULL });
				printf("execv failed\n");
			}
			else
			{
				if (OPEN_IN_SERIES)
				{
					printf("(parent) waiting [%d]\n", pid);
					wait_child(pid);
					printf("process [%d] terminated\n", pid);
				}
			}
			i++;
		}
	}
	if (!OPEN_IN_SERIES)
	{
		while ((pid = wait(&status)) > 0)
    	    printf("waiting %d..\n", pid);
	}
	printf("DONE\n");
	return (0);
}
