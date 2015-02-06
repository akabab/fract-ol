#include "fract.h"

int			hue_to_color(int hue)
{
	int		color;
	int		i;

	hue %= 360;
	i = 0;
	color = 0x000000; //0xFF0000;
	while (i != hue)
	{
		if (i < 60)
			color += 0x000400;
		else if (i < 120)
			color -= 0x040000;
		else if (i < 180)
			color += 0x000004;
		else if (i < 240)
			color -= 0x000400;
		else if (i < 300)
			color += 0x040000;
		else
			color -= 0x000004;
		i++;
	}
	return (color);
}

static int		burning_ship(int i)
{
	int		color;

	color = 0x000000;
	while (i != 0)
	{
		color += 0x010000;
		i--;
	}
	return (color);
}

int			fractal_ark(int x, int y, t_env *e)
{
	int		i;
	double	cp;
	t_z		z;
	t_z		const_z;

	const_z.a = z_xtoa(x, e);
	const_z.bi = z_ytobi(y, e) * -1;
	z.a = ft_abs_double(const_z.a);
	z.bi = ft_abs_double(const_z.bi);
	i = 0;
	while ((z.a * z.a + z.bi * z.bi) <= 4 && i < MAX_ITER)
	{
		cp = z.a;
		z.a = ft_abs_double(z.a) * ft_abs_double(z.a)
			- ft_abs_double(z.bi) * ft_abs_double(z.bi) + const_z.a;
		z.bi = 2 * ft_abs_double(cp) * ft_abs_double(z.bi) + const_z.bi;
		i++;
	}
	return (burning_ship(i * 2));
}

int			fractal_julia(int x, int y, t_env *e)
{
	int		i;
	t_z		z;
	double	cp;

	z.a = z_xtoa(x, e);
	z.bi = z_ytobi(y, e);
	i = 0;
	while ((z.a * z.a + z.bi * z.bi) <= 4 && i < MAX_ITER)
	{
		cp = z.a;
		z.a = z.a * z.a - z.bi * z.bi + e->c->a;
		z.bi = 2 * cp * z.bi + e->c->bi;
		i++;
	}
	if (i == MAX_ITER)
		return (0x000000);
	return (e->palette[e->start + ((i * e->step) % e->range)]);
	// return (hue_to_color(i * 2));
}

int			fractal_mandelbrot(int x, int y, t_env *e)
{
	int		i;
	double	cp;
	t_z		z;
	t_z		const_z;

	z.a = z_xtoa(x, e);
	z.bi = z_ytobi(y, e);
	const_z.a = z.a;
	const_z.bi = z.bi;
	i = 0;
	while ((z.a * z.a + z.bi * z.bi) <= 4 && i < MAX_ITER)
	{
		cp = z.a;
		z.a = z.a * z.a - z.bi * z.bi + const_z.a;
		z.bi = 2 * cp * z.bi + const_z.bi;
		i++;
	}
	if (i == MAX_ITER)
		return (0x000000);
	return (e->palette[e->start + ((i * e->step) % e->range)]);
	// return (hue_to_color(i * 2));
}

#define TH_N_LINE 60

typedef struct	s_th_data
{
	t_env	*e;
	int		start_y;
}				t_th_data;

static void * fn_compute_img (void * p_data)
{
	int			x;
	int			y;
	t_th_data	*data;
	int			color;

	data = (t_th_data *)p_data;
	y = data->start_y;
	while (y < data->start_y + TH_N_LINE && y < W_HEIGHT)
	{
		x = 0;
		while (x != W_WIDTH)
		{
			color = data->e->fract(x, y, data->e);
			my_pixel_put_to_image(data->e->img, x, y, color);
			x++;
		}
		y++;
	}
}

void		compute_fract(t_env *e)
{
	t_th_data	data[60];
	pthread_t	threads[60];
	int			i;
	int			ret;

	i = 0;
	while (i < 60)
	{
		ret = 0;
		data[i].e = e;
		data[i].start_y = i * TH_N_LINE;
		ret = pthread_create(&threads[i], NULL, fn_compute_img, &data[i]);
		if (ret)
			printf("ERROR\n");
		i++;
	}
	//wait for threads to finish
	i = 0;
	while (i < 60)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

void		criss_cross(t_env *e, int (*f_fract)(int, int, t_env *))
{
	int			x;
	int			y;
	int			color;

	x = 0;
	while (x != W_WIDTH)
	{
		y = 0;
		while (y != W_HEIGHT)
		{
			color = f_fract(x, y, e);
			my_pixel_put_to_image(e->img, x, y, color);
			y++;
		}
		x++;
	}
}
