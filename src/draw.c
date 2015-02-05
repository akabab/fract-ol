/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 11:13:50 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/30 11:14:08 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void			my_pixel_put_to_image(t_img *img, int x, int y, int color)
{
	int				i;
	int				mask;
	char			tmp_clr;
	int				offset;

	i = 0;
	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		while (i < (img->bpp / 8))
		{
			if (img->endian == 1)
				offset = img->bpp - 8 * (i + 1);
			else
				offset = 8 * i;
			mask = 0xFF << offset;
			tmp_clr = (color & mask) >> offset;
			img->addr[y * (img->lsize) + x * (img->bpp / 8) + i] = tmp_clr;
			i++;
		}
	}
}

void	draw_palette(int *palette, int size, t_env *e)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < 20)
		{
			my_pixel_put_to_image(e->img, x, y, palette[y]);
			x++;
		}
		y++;
	}
	x = 0;
	while (x++ < 25)
		my_pixel_put_to_image(e->img, x, e->start, 0xFFFFF);
	x = 0;
	while (x++ < 25)
		my_pixel_put_to_image(e->img, x, (e->start + e->range) % PALETTE_SIZE, 0xFFFFF);
}

