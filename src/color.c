#include "color.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

t_color	hexToRgb(int hex)
{
	t_color	col;

	// col.r = (double)((hex >> 16) % 256) / 255;
	// col.g = (double)((hex >> 8) % 256) / 255;
	// col.b = (double)(hex % 256) / 255;
	col.r = (double)((hex & 0xFF0000) >> 16) / 255;
	col.g = (double)((hex & 0x00FF00) >> 8 ) / 255;
	col.b = (double)((hex & 0x0000FF)      ) / 255;
	return (col);
}

int		rgbToHex(double r, double g, double b)
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

void	color_add(t_color *col1, t_color *col2)
{
	col1->r += col2->r;
	col1->g += col2->g;
	col1->b += col2->b;
}

void	color_sub(t_color *col1, t_color *col2)
{
	col1->r -= col2->r;
	col1->g -= col2->g;
	col1->b -= col2->b;
}

void	color_mul(t_color *col1, double factor)
{
	col1->r *= factor;
	col1->g *= factor;
	col1->b *= factor;
}

void	color_div(t_color *col1, double factor)
{
	col1->r /= factor;
	col1->g /= factor;
	col1->b /= factor;
}

// BLACK---C1--------WHITE--------C2---BLACK
int		*generate_bw_gradient_palette(t_color color1, t_color color2, int size)
{
	int			*palette;
	int			i;
	t_color		b_offset_col1;
	t_color		b_offset_col2;
	t_color		w_offset_col1;
	t_color		w_offset_col2;
	t_color		gradient_col;

	b_offset_col1.r = (color1.r - 0.0) / (size / 4);
	b_offset_col1.g = (color1.g - 0.0) / (size / 4);
	b_offset_col1.b = (color1.b - 0.0) / (size / 4);

	b_offset_col2.r = (color2.r - 0.0) / (size / 4);
	b_offset_col2.g = (color2.g - 0.0) / (size / 4);
	b_offset_col2.b = (color2.b - 0.0) / (size / 4);

	w_offset_col1.r = (1.0 - color1.r) / (size / 4);
	w_offset_col1.g = (1.0 - color1.g) / (size / 4);
	w_offset_col1.b = (1.0 - color1.b) / (size / 4);

	w_offset_col2.r = (1.0 - color2.r) / (size / 4);
	w_offset_col2.g = (1.0 - color2.g) / (size / 4);
	w_offset_col2.b = (1.0 - color2.b) / (size / 4);

	gradient_col.r = 0.0;
	gradient_col.g = 0.0;
	gradient_col.b = 0.0;
	i = 0;
	if ((palette = (int *)malloc(sizeof(int) * size)))
	{
		while (i < size)
		{
			if (i < size * 1/4)
				color_add(&gradient_col, &b_offset_col1);
			else if (i < size * 2/4)
				color_add(&gradient_col, &w_offset_col1);
			else if (i < size * 3/4)
				color_sub(&gradient_col, &w_offset_col2);
			else
				color_sub(&gradient_col, &b_offset_col2);
			palette[i] = rgbToHex(gradient_col.r, gradient_col.g, gradient_col.b);
			i++;
		}
	}
	return (palette);
}

// BLACK---C1----------------C2---BLACK
int		*generate_b_gradient_palette(t_color color1, t_color color2, int size)
{
	int			*palette;
	int			i;
	t_color		b_offset_col1;
	t_color		b_offset_col2;
	t_color		offset_col;
	t_color		gradient_col;

	b_offset_col1.r = (color1.r - 0.0) / (size / 4);
	b_offset_col1.g = (color1.g - 0.0) / (size / 4);
	b_offset_col1.b = (color1.b - 0.0) / (size / 4);

	b_offset_col2.r = (color2.r - 0.0) / (size / 4);
	b_offset_col2.g = (color2.g - 0.0) / (size / 4);
	b_offset_col2.b = (color2.b - 0.0) / (size / 4);

	offset_col.r = (color2.r - color1.r) / (size / 2);
	offset_col.g = (color2.g - color1.g) / (size / 2);
	offset_col.b = (color2.b - color1.b) / (size / 2);

	gradient_col.r = 0.0;
	gradient_col.g = 0.0;
	gradient_col.b = 0.0;
	i = 0;
	if ((palette = (int *)malloc(sizeof(int) * size)))
	{
		while (i < size)
		{
			if (i < size * 1/4)
			{
				gradient_col.r += b_offset_col1.r;
				gradient_col.g += b_offset_col1.g;
				gradient_col.b += b_offset_col1.b;
			}
			else if (i < size * 3/4)
			{
				gradient_col.r += offset_col.r;
				gradient_col.g += offset_col.g;
				gradient_col.b += offset_col.b;
			}
			else
			{
				gradient_col.r -= b_offset_col2.r;
				gradient_col.g -= b_offset_col2.g;
				gradient_col.b -= b_offset_col2.b;
			}
			palette[i] = rgbToHex(gradient_col.r, gradient_col.g, gradient_col.b);
			i++;
		}
	}
	return (palette);
}

// C1 --------WHITE-------- C2
int		*generate_w_gradient_palette(t_color color1, t_color color2, int size)
{
	int			*palette;
	int			i;
	t_color		offset_col1;
	t_color		offset_col2;
	t_color		gradient_col;

	offset_col1.r = (1.0 - color1.r) / (size / 2);
	offset_col1.g = (1.0 - color1.g) / (size / 2);
	offset_col1.b = (1.0 - color1.b) / (size / 2);

	offset_col2.r = (1.0 - color2.r) / (size / 2);
	offset_col2.g = (1.0 - color2.g) / (size / 2);
	offset_col2.b = (1.0 - color2.b) / (size / 2);

	gradient_col = color1;
	i = 0;
	if ((palette = (int *)malloc(sizeof(int) * size)))
	{
		while (i < size)
		{
			if (i < size / 2)
			{
				gradient_col.r += offset_col1.r;
				gradient_col.g += offset_col1.g;
				gradient_col.b += offset_col1.b;
			}
			else
			{
				gradient_col.r -= offset_col2.r;
				gradient_col.g -= offset_col2.g;
				gradient_col.b -= offset_col2.b;
			}
			palette[i] = rgbToHex(gradient_col.r, gradient_col.g, gradient_col.b);
			i++;
		}
	}
	return (palette);
}

// C1 --------------------- C2
int		*generate_gradient_palette(t_color color1, t_color color2, int size)
{
	int			*palette;
	int			i;
	t_color		offset_col;
	t_color		gradient_col;

	offset_col.r = (color2.r - color1.r) / size;
	offset_col.g = (color2.g - color1.g) / size;
	offset_col.b = (color2.b - color1.b) / size;
	gradient_col = color1;
	i = 0;
	if ((palette = (int *)malloc(sizeof(int) * size)))
	{
		while (i < size)
		{
			gradient_col.r += offset_col.r;
			gradient_col.g += offset_col.g;
			gradient_col.b += offset_col.b;
			palette[i] = rgbToHex(gradient_col.r, gradient_col.g, gradient_col.b);
			i++;
		}
	}
	return (palette);
}

int		*generate_palette(int size)
{
	int			*palette;
	int			i;
	t_color		color;
	int			r;
	double		offset;

	if ((palette = (int *)malloc(sizeof(int) * size)))
	{
		color.r = 1.0;
		color.g = 0.0;
		color.b = 0.0;
		r = size / 6;
		offset = (double)(1.0 / r);
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
