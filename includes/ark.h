/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:52:18 by ycribier          #+#    #+#             */
/*   Updated: 2015/05/19 18:14:08 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARK_H
# define ARK_H

# define ARK_ORIGIN_A		-1.625331
# define ARK_ORIGIN_BI		0.017875
# define ARK_ZOOM			0.028505

# include "structs.h"

int		fractal_ark(int x, int y, t_env *e);
void	init_ark(t_env *e);

#endif
