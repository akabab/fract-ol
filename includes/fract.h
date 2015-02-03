#ifndef FRACT_H
# define FRACT_H

# include "libft.h"
# include "list.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <mlx.h>
# include </usr/X11R6/include/X11/X.h>
# include <X11/Xutil.h>

# define W_WIDTH			800
# define W_HEIGHT			800

# define KEY_UP				65362
# define KEY_DOWN			65364
# define KEY_LEFT			65361
# define KEY_RIGHT			65363
# define KEY_ESC			65307
# define KEY_SHIFT			65505
# define KEY_MORE			65451
# define KEY_LESS			65453
# define KEY_SPACE			32
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_RESET			114

# define SCROLL_UP			4
# define SCROLL_DOWN		5

# define ZOOM_IN_FACTOR		0.9
# define ZOOM_OUT_FACTOR	1.1

# define RANGE_C			0.02
# define RANGE_ORIGIN		0.05

# define MAX_ITER			180

# define MANDEL_C_A			-0.62
# define MANDEL_C_BI		-1.18
# define MANDEL_ORIGIN_A	-0.62
# define MANDEL_ORIGIN_BI	-0.04
# define MANDEL_ZOOM		0.7

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
	int				(*fract)(int, int, struct s_env *);
	t_z				*c;
	t_z				*origin;
	double			zoom;
}					t_env;

/*
**		criss_cross.c
*/
void		criss_cross(t_env *e, int (*ft)(int, int, t_env *));
int			fractal_julia(int x, int y, t_env *e);
int			fractal_mandelbrot(int x, int y, t_env *e);
int			fractal_newton(int x, int y, t_env *e);

/*
**		env.c
*/
void		free_env(t_env *e);
void		init_params(t_env *e);
t_env		*init_env(char *title);

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

/*
**		mlx_handler.c
*/
int			loop_hook(t_env *e);
void		mlx_handler(t_env *e);

/*
**		complexe.c
*/
t_z			*coord_to_z(int x, int y, t_env *e);
double		z_xtoa(int x, t_env *e);
double		z_ytobi(int y, t_env *e);

/*
**		tools.c
*/
double		ft_abs_double(double n);

#endif
