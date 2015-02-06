#include "fract.h"

static int g_th_done = 0;

static void * compute_part (void * p_data)
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
		while (x < W_WIDTH)
		{
			color = data->e->fract(x, y, data->e);
			my_pixel_put_to_image(data->e->img, x, y, color);
			x++;
		}
		y++;
	}
	g_th_done++;
	printf("Computing::%d%%\n", (int)(((float)g_th_done / TH_N_THREADS) * 100));
}

void		thread_compute_fract(t_env *e)
{
	t_th_data	data[TH_N_THREADS];
	pthread_t	threads[TH_N_THREADS];
	int			i;
	int			ret;

	//
	g_th_done = 0;
	//

	i = 0;
	while (i < TH_N_THREADS)
	{
		ret = 0;
		data[i].e = e;
		data[i].start_y = i * TH_N_LINE;
		ret = pthread_create(&threads[i], NULL, compute_part, &data[i]);
		if (ret)
			exit(-1);
		i++;
	}
	i = 0;
	while (i < TH_N_THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
