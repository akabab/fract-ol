/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:52:18 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/09 17:54:04 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void		clean(t_env *e)
{
	int		i;
	int		j;
	int		color;

	color = 0x000000;
	i = 0;
	while (i != W_WIDTH)
	{
		j = 0;
		while (j != W_HEIGHT)
		{
			my_pixel_put_to_image(e->img, i, j, color);
			j++;
		}
		i++;
	}
}

static void		forest(int deep, t_z start, t_z next, t_env *e)
{
	double		length;
	double		height;
	double		dist;
	t_z			pt1;
	t_z			pt2;

	branch(0, start, next, e);
	if (deep > 5 || (deep > e->c->a + 2))
		return ;
	deep++;
	length = next.bi - start.bi;
	height = length * (2. / 5);
	dist = length * (3. / 5);
	pt1.a = start.a + dist;
	pt1.bi = start.bi;
	pt2.a = pt1.a;
	pt2.bi = pt1.bi + height;
	forest(deep, pt1, pt2, e);
	pt1.a = start.a - dist;
	pt2.a = pt1.a;
	forest(deep, pt1, pt2, e);
}

void			tree(t_env *e)
{
	int		deep;
	t_z		start;
	t_z		next;

	clean(e);
	start.a = 0;
	start.bi = 0;
	next.a = 0;
	next.bi = 2.;
	deep = 0;
	forest(deep, start, next, e);
}

void			init_tree(t_env *e)
{
	e->c->a = TREE_CONST_A;
	e->c->bi = TREE_CONST_BI;
	e->origin->a = TREE_ORIGIN_A;
	e->origin->bi = TREE_ORIGIN_BI;
	e->zoom = TREE_ZOOM;
}
