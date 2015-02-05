/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 11:13:50 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/05 11:41:48 by jspezia          ###   ########.fr       */
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

void	draw_line_1(int color, t_coord *pt1, t_coord *pt2, t_img *img)
{
	int	x;
	int	y;

	x = pt1->x;
	while (x <= pt2->x)
	{
		y = pt1->y + ((pt2->y - pt1->y) * (x - pt1->x)) / (pt2->x - pt1->x);
		my_pixel_put_to_image(img, x, y, color);
		x++;
	}
}

void	draw_line_2(int color, t_coord *pt1, t_coord *pt2, t_img *img)
{
	int	x;
	int	y;

	y = pt1->y;
	if (pt1->x == pt2->x && pt1->y == pt2->y)
	{
		my_pixel_put_to_image(img, pt1->x, pt1->y, color);
		return ;
	}
	while (y <= pt2->y)
	{
		x = pt1->x + ((pt2->x - pt1->x) * (y - pt1->y)) / (pt2->y - pt1->y);
		my_pixel_put_to_image(img, x, y, color);
		y++;
	}
}

void	draw_line(int color, t_coord *pt1, t_coord *pt2, t_img *img)
{
	if ((ft_abs(pt1->x - pt2->x) > ft_abs(pt1->y - pt2->y)))
	{
		if (pt1->x < pt2->x)
			draw_line_1(color, pt1, pt2, img);
		else
			draw_line_1(color, pt2, pt1, img);
	}
	else
	{
		if (pt1->y < pt2->y)
			draw_line_2(color, pt1, pt2, img);
		else
			draw_line_2(color, pt2, pt1, img);
	}
}
