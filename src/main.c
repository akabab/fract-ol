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

	if (ac < 2)
		ft_printf("Usage: %s <fract> ... {julia, mandel, ark, tree, ...}\n",
				av[0]);
	i = 1;
	while (i < ac)
	{
		if ((ft_fract = match_fractal(av[i])))
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
