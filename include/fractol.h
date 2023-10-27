/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:26:04 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/27 15:22:02 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <float.h>

//# include <X11/X.h>

# include "keys.h"
# include "../ft_printf/ft_printf.h"

# define WIDTH 600
# define HEIGHT 600
# define MAX_ITER 12
# define ON_DESTROY 17
# define ON_MOUSEMOVE 6
# define MAX_LEN_DBL 317
# define HYPOTENUSE 4
# define TRANSITION_SPEED 0.70

// Colors
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define PALETTE_LEN 11

typedef struct s_trgb
{
	uint8_t		t1;
	uint8_t		t2;
	uint8_t		r1;
	uint8_t		r2;
	uint8_t		g1;
	uint8_t		g2;
	uint8_t		b1;
	uint8_t		b2;
	uint8_t		t;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint32_t	color;
}				t_trgb;

typedef struct s_color
{
	uint32_t	color1;
	uint32_t	color2;
}				t_color;

typedef struct s_color_palette
{
	t_color	colors[PALETTE_LEN];
}			t_color_palette;

enum e_fnames
{
	Mandelbrot,
	Julia,
	Burning_Ship
};

typedef struct s_scale
{
	double	value_to_scale;
	double	target_min;
	double	target_max;
	double	original_min;
	double	original_max;
}			t_scale;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_complex
{
	double	real;
	double	imag;
}		t_complex;

typedef struct s_julia
{
	t_complex	julia_complex;
}		t_julia;

typedef struct s_scales
{
	t_scale	scale_real;
	t_scale	scale_imag;
	t_scale	scale_color;
}	t_scales;

typedef struct s_fractol
{
	t_vars			vars;
	t_data			data;
	t_julia			julia;
	t_color_palette	color_palette;
	enum e_fnames	fname;
	double			pos_x;
	double			pos_y;
	double			zoom;
	char			*fractal_name;
	int				max_iter;
	int				is_fixed;
	int				color_type;
	int				power;
	int				set_colors;
}					t_fractol;

// inits
void		init_scale_real(t_scale *scale_real, int x);
void		init_scale_imag(t_scale *scale_imag, int y);
void		init_scale_color(t_scale *scale_color, int i, t_fractol *fractol);
void		init_mlx(t_fractol *fractol);
void		init_fractol(t_fractol *fractol, char **av);
void		init_t_scale(t_scale *scale);
void		init_t_scales(t_scales *scales);
void		init_t_complex(int len, t_complex **complex);
void		init_t_fractol(t_fractol *fractol);

// hooks
int			hook_mouse_handler(int action, int x, int y, t_fractol *fractol);
int			window_close_hook(t_fractol *fractol);
int			check_mouse_pos(int x, int y, t_fractol *fractol);
void		close_hook(t_fractol *fractol);
void		move_hook(int keycode, t_fractol *fractol);
void		iters_hook(int keycode, t_fractol *fractol);
void		reset_hook(int keycode, t_fractol *fractol);
void		zoom_hook(int keycode, t_fractol *fractol);
void		hook_handler(t_fractol *fractol);
void		color_type(int keycode, t_fractol *fractol);
void		close_hook(t_fractol *fractol);

// mlx_utils
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);

// utils
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isdigit(int c);
void		print_help_usage(void);
double		ft_strtod(const char *str);
size_t		ft_strlen(char *str);

// mmath utils
double		interpolate(t_scale *scale);
double		interpolate_color(t_scale *scale, t_color colors);
t_complex	add_complex(t_complex z_1, t_complex z_2);
t_complex	subtract_complex(t_complex z_1, t_complex z_2);
t_complex	divide_complex(t_complex z_1, t_complex z_2);
t_complex	mult_complex(t_complex z_1, t_complex z_2);
t_complex	power_complex(t_complex z, int n);
t_complex	fabs_complex(t_complex c);

// fractals
void		select_complex_numbers(t_complex *z, t_complex *c,
				t_scales *scales, t_fractol *fractol);
void		check_fractal(t_fractol *fractol, int ac, char **av);
void		draw_fractal(t_fractol *fractol);

// colors
void		type_zero(t_scale *scale_color);
void		type_one(t_scale *scale_color, t_fractol *fractol);
void		type_two(t_scale *scale_color, t_fractol *fractol);
void		type_three(t_scale *scale_color, t_fractol *fractol);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);
int			create_trgb(int t, int r, int g, int b);
void		set_color_palette(t_fractol *fractol);
double		interpolate_colors_bits(t_scale *scale, t_color colors);

#endif
