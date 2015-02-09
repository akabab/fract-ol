/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_tree_branch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:52:18 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/09 17:54:06 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void		leaf2(int deep, t_z start, t_z next, t_env *e)
{
	double		lenght;
	t_z			pt;

	lenght = ft_abs_double(start.a - next.a) > ft_abs_double(start.bi - next.bi)
		? ft_abs_double(start.a - next.a) : ft_abs_double(start.bi - next.bi);
	lenght *= 2. / 5;
	pt.a = next.a;
	pt.bi = (start.bi > next.bi) ? next.bi - lenght : next.bi + lenght;
	branch(deep, next, pt, e);
	pt.bi = next.bi;
	pt.a = next.a + lenght;
	branch(deep, next, pt, e);
	pt.a = next.a - lenght;
	branch(deep, next, pt, e);
}

static void		leaf1(int deep, t_z start, t_z next, t_env *e)
{
	double		lenght;
	t_z			pt;

	lenght = ft_abs_double(start.a - next.a) > ft_abs_double(start.bi - next.bi)
		? ft_abs_double(start.a - next.a) : ft_abs_double(start.bi - next.bi);
	lenght *= 2. / 5;
	pt.a = (start.a > next.a) ? next.a - lenght : next.a + lenght;
	pt.bi = next.bi;
	branch(deep, next, pt, e);
	pt.a = next.a;
	pt.bi = next.bi + lenght;
	branch(deep, next, pt, e);
	pt.bi = next.bi - lenght;
	branch(deep, next, pt, e);
}

static void		leaf(int deep, t_z start, t_z next, t_env *e)
{
	if (start.bi == next.bi)
		leaf1(deep, start, next, e);
	if (start.a == next.a)
		leaf2(deep, start, next, e);
	return ;
}

void			branch(int deep, t_z start, t_z next, t_env *e)
{
	t_coord		first;
	t_coord		second;
	int			color;
	int			i;

	if (deep > (int)((e->c->bi - 1.) * 5) || deep > 10)
		return ;
	color = 0xAA5500;
	i = 0;
	while (i != deep)
	{
		color -= 0x110000;
		i++;
	}
	first.x = z_atox(start.a, e);
	first.y = z_bitoy(start.bi, e);
	second.x = z_atox(next.a, e);
	second.y = z_bitoy(next.bi, e);
	draw_line(color, &first, &second, e->img);
	deep++;
	leaf(deep, start, next, e);
}
