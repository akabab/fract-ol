#ifndef COLOR_H
# define COLOR_H

# define PALETTE_SIZE	360

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

t_color	hexToRgb(int hex);
int		rgbToHex(double r, double g, double b);

int		*generate_bw_gradient_palette(t_color color1, t_color color2, int size);
int		*generate_b_gradient_palette(t_color color1, t_color color2, int size);
int		*generate_w_gradient_palette(t_color color1, t_color color2, int size);
int		*generate_gradient_palette(t_color color1, t_color color2, int size);
int		*generate_palette(int size);

#endif
