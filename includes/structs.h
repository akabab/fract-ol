/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 18:11:30 by ycribier          #+#    #+#             */
/*   Updated: 2015/05/19 18:18:58 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
**		tools
*/
# include "libft.h"
# include "color.h"

typedef struct		s_keys
{
	t_bool	up;
	t_bool	down;
	t_bool	right;
	t_bool	left;
}					t_keys;

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

typedef struct		s_z
{
	double			a;
	double			bi;
}					t_z;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	char			*title;
	t_keys			*keys;
	t_col_palette	*col;
	int				(*fract)(int, int, struct s_env *);
	t_z				*c;
	t_z				*origin;
	int				power;
	double			zoom;
	t_bool			need_recompute;
	t_bool			multi_threads;
}					t_env;

#endif
