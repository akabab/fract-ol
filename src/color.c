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

int		main(int argc, char *argv[])
{
	float	r;
	float	g;
	float	b;
	int		color;

	if (argc < 4)
		return printf("usage: ./color r g b\n");
	r = (float)atof(argv[1]);
	g = (float)atof(argv[2]);
	b = (float)atof(argv[3]);
	color = rgbToHex(r, g, b);
	printf("Color: 0x%x\n", color);
}
