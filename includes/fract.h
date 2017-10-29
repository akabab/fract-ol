/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:52:18 by ycribier          #+#    #+#             */
/*   Updated: 2015/05/19 18:37:16 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <mlx.h>
# include "libft.h"
# include "list.h"

/*
**		tools
*/
# include "x.h"
# include "structs.h"
# include "color.h"
# include "keys.h"

/*
**		fractals
*/
# include "julia.h"
# include "mandel.h"
# include "ark.h"
# include "tree.h"

# define W_WIDTH			600
# define W_HEIGHT			600

# define ZOOM_IN_FACTOR		0.9
# define ZOOM_OUT_FACTOR	1.1

# define RANGE_C			0.02
# define RANGE_ORIGIN		0.005

# define MAX_ITER			360

# define OPEN_IN_SERIES		TRUE

/*
**		env.c
*/
void				free_env(t_env *e);
void				init_params(t_env *e);
t_env				*init_env(char *title);

/*
**		draw.c
*/
void				my_pixel_put_to_image(t_img *img, int x, int y, int color);
void				draw_line(int color, t_coord *pt1, t_coord *pt2, t_img *e);
void				draw_palette(int *palette, int size, t_env *e);

/*
**		hook.c
*/
int					pointer_motion_hook(int x, int y, t_env *e);
int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);

/*
**		mlx_handler.c
*/
void				mlx_handler(t_env *e);

/*
**		complexe.c
*/
t_z					*coord_to_z(int x, int y, t_env *e);
double				z_xtoa(int x, t_env *e);
double				z_ytobi(int y, t_env *e);
int					z_atox(double a, t_env *e);
int					z_bitoy(double bi, t_env *e);

/*
**		tools.c
*/
double				ft_abs_double(double n);
double				d_power(double nb, int power);

/*
**		criss_cross.c
*/
void				criss_cross(t_env *e);

/*
**		thread.c
*/
# define TH_N_THREADS	8
# define TH_N_LINE		((int)(W_HEIGHT / TH_N_THREADS) + 1)

typedef struct		s_th_data
{
	t_env			*e;
	int				start_y;
}					t_th_data;

void				thread_compute_fract(t_env *e);

#endif
