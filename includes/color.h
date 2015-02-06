#ifndef COLOR_H
# define COLOR_H

# define PALETTE_SIZE	360

# define COL_BLACK		0x000000
# define COL_WHITE		0xFFFFFF
# define COL_RED		0xFF0000
# define COL_BLUE		0x00FF00
# define COL_GREEN		0x0000FF
# define COL_CYAN		0x00FFFF
# define COL_YELLOW		0xFFFF00
# define COL_PURPLE		0xFF00FF

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
