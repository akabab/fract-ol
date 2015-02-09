#ifndef FRACT_H
# define FRACT_H

# include "libft.h"
# include "list.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <mlx.h>
# include </usr/X11R6/include/X11/X.h>
# include </usr/X11R6/include/X11/Xutil.h>

/*
**		tools
*/
# include "color.h"
# include "keys.h"

/*
**		fractals
*/
# include "julia.h"
# include "mandel.h"
# include "ark.h"
# include "tree.h"

# define W_WIDTH			800
# define W_HEIGHT			800

# define ZOOM_IN_FACTOR		0.99
# define ZOOM_OUT_FACTOR	1.01

# define RANGE_C			0.02
# define RANGE_ORIGIN		0.005

# define MAX_ITER			360

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
}					t_env;

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
**		thread.c
*/
# define TH_N_THREADS	8
# define TH_N_LINE		((int)(W_HEIGHT / TH_N_THREADS) + 1)

typedef struct		s_th_data
{
	t_env	*e;
	int		start_y;
}					t_th_data;

void				thread_compute_fract(t_env *e);

#endif
