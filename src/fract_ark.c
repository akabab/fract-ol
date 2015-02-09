/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:52:18 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/09 18:04:16 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static int	burning_ship(int i)
{
	int		color;

	color = 0x000000;
	while (i != 0)
	{
		color += 0x000100;
		i--;
	}
	return (color);
}

int			fractal_ark(int x, int y, t_env *e)
{
	int		i;
	double	cp;
	t_z		z;
	t_z		const_z;

	const_z.a = z_xtoa(x, e);
	const_z.bi = z_ytobi(y, e) * -1;
	z.a = ft_abs_double(const_z.a);
	z.bi = ft_abs_double(const_z.bi);
	i = 0;
	while ((z.a * z.a + z.bi * z.bi) <= 4 && i < MAX_ITER)
	{
		cp = z.a;
		z.a = ft_abs_double(z.a) * ft_abs_double(z.a)
			- ft_abs_double(z.bi) * ft_abs_double(z.bi) + const_z.a;
		z.bi = 2 * ft_abs_double(cp) * ft_abs_double(z.bi) + const_z.bi;
		i++;
	}
	return (burning_ship(i * 2));
}

void		init_ark(t_env *e)
{
	e->origin->a = ARK_ORIGIN_A;
	e->origin->bi = ARK_ORIGIN_BI;
	e->zoom = ARK_ZOOM;
}
