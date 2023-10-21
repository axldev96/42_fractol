/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:26:04 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/21 08:13:34 by acaceres         ###   ########.fr       */
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
# if __linux__
#  include <X11/X.h>
# endif

# include "keys.h"
# include "../ft_printf/ft_printf.h"

# define WIDTH 600
# define HEIGHT 600
# define MAX_ITER 20

# define ON_DESTROY 17

# define MAX_LEN_DBL 317

# define HYPOTENUSE 4.0

// Colors
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define BEIGE 0x00F5F5DC
# define BISQUE 0x00FFE4C4

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
	t_vars		vars;
	t_data		data;
	t_julia		julia;
	double		pos_x;
	double		pos_y;
	double		zoom;
	char		*fractal_name;
	int			max_iter;
}				t_fractol;

// inits
void		init_scale_real(t_scale *scale_real, int x);
void		init_scale_imag(t_scale *scale_imag, int y);
void		init_scale_color(t_scale *scale_color, int i);
void		init_mlx(t_fractol *fractol);
void		init_fractol(t_fractol *fractol, char **av);
void		init_t_scale(t_scale *scale);
void		init_t_scales(t_scales *scales);
void		init_t_complex(int len, t_complex **complex);
void		init_t_fractol(t_fractol *fractol);

// hooks

void		close_hook(t_fractol *fractol);
void		move_hook(int keycode, t_fractol *fractol);
void		iters_hook(int keycode, t_fractol *fractol);
void		reset_hook(int keycode, t_fractol *fractol);
void		zoom_hook(int keycode, t_fractol *fractol);
void		hook_handler(t_fractol *fractol);
int			hook_mouse_handler(int action, int x, int y, t_fractol *fractol);
int			window_close_hook(t_fractol *fractol);
int			check_mouse_pos(int x, int y, t_fractol *fractol);

// mlx_utils
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);

// utils
void		check_fractal(t_fractol *fractol, int ac, char **av);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		interpolate(t_scale *scale);
double		ft_strtod(const char *str);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z_1);
void		select_complex_numbers(t_complex *z, t_complex *c,
				t_scales *scales, t_fractol *fractol);
int			ft_isdigit(int c);
size_t		ft_strlen(char *str);
void		print_help_usage(void);

// fractals
void		draw_fractal(t_fractol *fractol);

#endif
