#ifndef FRACT_H
# define FRACT_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <mlx.h>
# include </usr/X11R6/include/X11/X.h>
# include <X11/Xutil.h>

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
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100

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

typedef struct		s_Z
{
	double			a;
	double			bi;
}					t_Z;

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
	t_keys			*keys;
	t_Z				*c;
	t_Z				*origin;
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

/*
**		hook.c
*/
int			pointer_motion_hook(int x, int y, t_env *e);
int			expose_hook(t_env *e);
int			key_hook(int keycode, t_env *e);
int			mouse_hook(int button, int x, int y, t_env *e);
int			loop_hook(t_env *e);

/*
**		complexe.c
*/
t_Z		*coord_to_z(int x, int y, t_env *e);
double	Z_a(int x, t_env *e);
double	Z_bi(int y, t_env *e);

/*
**		tools.c
*/
double		ft_abs_double(double n);

#endif
