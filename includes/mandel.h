#ifndef MANDEL_H
# define MANDEL_H

# define MANDEL_ORIGIN_A	-0.62
# define MANDEL_ORIGIN_BI	-0.04
# define MANDEL_ZOOM		0.7
# define MANDEL_POWER		1
# define MANDEL_COL1		0x4169E1
# define MANDEL_COL2		0xE1B941

typedef struct s_env	t_env;

int			fractal_mandelbrot(int x, int y, t_env *e);
void		init_mandel(t_env *e);

#endif
