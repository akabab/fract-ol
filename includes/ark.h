#ifndef ARK_H
# define ARK_H

# define ARK_ORIGIN_A		-1.625331
# define ARK_ORIGIN_BI		0.017875
# define ARK_ZOOM			0.028505

typedef struct s_env	t_env;

int		fractal_ark(int x, int y, t_env *e);
void	init_ark(t_env *e);

#endif
