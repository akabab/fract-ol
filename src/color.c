#include "fract.h"

#include <stdio.h>
#include <stdlib.h>

int		rgbToHex(float r, float g, float b)
{
	int		hexColor;

	r = r > 1.0 ? 1.0 : r;
	r = r < 0.0 ? 0.0 : r;
	g = g > 1.0 ? 1.0 : g;
	g = g < 0.0 ? 0.0 : g;
	b = b > 1.0 ? 1.0 : b;
	b = b < 0.0 ? 0.0 : b;
	hexColor = 0x000000;

	hexColor += (int)(r * 0xFF) << 16;
	hexColor += (int)(g * 0xFF) << 8;
	hexColor += (int)(b * 0xFF);
	return (hexColor);
}

typedef struct		s_color
{
	float		r;
	float		g;
	float		b;
}					t_color;

int		*generate_palette(int size)
{
	int			*palette;
	int			i;
	t_color		color;
	int			r;
	float		offset;

	if ((palette = (int *)malloc(sizeof(int) * size)))
	{
		color.r = 1.0;
		color.g = 0.0;
		color.b = 0.0;
		r = size / 6;
		offset = (float)(1.0 / r);
		// printf("r: %d, offset:%f\n", r, offset);
		i = 0;
		while (i < size)
		{
			if (i < r * 1)
				color.g += offset;
			else if (i < r * 2)
				color.r -= offset;
			else if (i < r * 3)
				color.b += offset;
			else if (i < r * 4)
				color.g -= offset;
			else if (i < r * 5)
				color.r += offset;
			else if (i < r * 6)
				color.b -= offset;
			palette[i] = rgbToHex(color.r, color.g, color.b);
			i++;
		}
	}
	return (palette);
}

void	print_palette(int *palette, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("[%d] %x\n", i, palette[i]);
		i++;
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
			// printf("[%d] %x\n", i, palette[i]);
			my_pixel_put_to_image(e->img, x, y, palette[y]);
			x++;
		}
		y++;
	}
	//cursor
	x = 0;
	while (x++ < 25)
		my_pixel_put_to_image(e->img, x, e->start, 0xFFFFF);
	x = 0;
	while (x++ < 25)
		my_pixel_put_to_image(e->img, x, (e->start + e->range) % PALETTE_SIZE, 0xFFFFF);
}
