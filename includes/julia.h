#ifndef JULIA_H
# define JULIA_H

# define JULIA_A			0.0
# define JULIA_BI			0.0
# define JULIA_ORIGIN_A		0.0
# define JULIA_ORIGIN_BI	0.0
# define JULIA_ZOOM			1.0
# define JULIA_POWER		1
# define JULIA_COL1			0x4169E1
# define JULIA_COL2			0xE1B941

typedef struct s_env	t_env;

int			fractal_julia(int x, int y, t_env *e);
void		init_julia(t_env *e);

#endif
