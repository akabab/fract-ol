/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:52:18 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/09 18:30:42 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void		*compute_part(void *p_data)
{
	int			x;
	int			y;
	t_th_data	*data;
	int			color;

	data = (t_th_data *)p_data;
	y = data->start_y;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			color = data->e->fract(x, y, data->e);
			my_pixel_put_to_image(data->e->img, x, y, color);
			x++;
		}
		y += TH_N_THREADS;
	}
	return (NULL);
}

void			thread_compute_fract(t_env *e)
{
	t_th_data	data[TH_N_THREADS];
	pthread_t	threads[TH_N_THREADS];
	int			i;

	i = 0;
	while (i < TH_N_THREADS)
	{
		data[i].e = e;
		data[i].start_y = i;
		if (pthread_create(&threads[i], NULL, compute_part, &data[i]) != 0)
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
