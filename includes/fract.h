/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 15:01:51 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/30 11:33:58 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H


# define W_HEIGHT	800
# define W_WIDTH	800

# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_ESC	65307
# define KEY_SHIFT	65505
# define KEY_MORE	65451
# define KEY_LESS	65453
# define KEY_SPACE	32
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_W		119

#include "libft.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include </usr/X11R6/include/X11/X.h>
#include <unistd.h>
#include <X11/Xutil.h>

typedef struct		s_img
{
	void			*id;
	int				width;
	int				height;
	char			*addr;
	int				bpp;
	int				lsize;
	int				endian;
}					t_img;

typedef struct		s_keys
{
	t_bool			up;
	t_bool			down;
	t_bool			right;
	t_bool			left;
}					t_keys;

typedef struct		s_pt
{
	double			x;
	double			y;
}					t_pt;


typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_keys			*keys;
	t_pt			*c;
	t_pt			*origin;
	double			zoom;
}					t_env;

/*
**		criss_cross.c
*/
void		criss_cross(t_env *e, int (*ft)(int, int, t_env *));
int			fractal_julia(int x, int y, t_env *e);

/*
**		keys.c
*/
int			key_press(int keycode, t_env *e);
int			key_release(int keycode, t_env *e);
void		manage_keys(t_env *e);
t_keys		*init_keys(void);

/*
**		draw.c
*/
void		my_pixel_put_to_image(t_img *img, int x, int y, int color);

#endif
