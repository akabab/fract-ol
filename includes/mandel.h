/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:52:18 by ycribier          #+#    #+#             */
/*   Updated: 2015/05/19 18:16:55 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDEL_H
# define MANDEL_H

# define MANDEL_ORIGIN_A	-0.62
# define MANDEL_ORIGIN_BI	-0.04
# define MANDEL_ZOOM		0.7
# define MANDEL_POWER		1
# define MANDEL_COL1		0x30F2BB
# define MANDEL_COL2		0xF23067

# include "structs.h"

int			fractal_mandelbrot(int x, int y, t_env *e);
void		init_mandel(t_env *e);

#endif
