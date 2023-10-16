/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:26:04 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/14 22:41:55 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <X11/X.h>

# define WIDTH 1024
# define HEIGHT 768
# define MAX_ITER 30

# define HYPOTENUSE 4.0

# define BLACK 0x00000000
# define WHITE 0x00FFFFFF

// LINUX KEYS
# define ESCAPE_LINUX 65307
# define ARROW_UP_LINUX 65362
# define ARROW_DOWN_LINUX 65364
# define ARROW_RIGHT_LINUX 65363
# define ARROW_LEFT_LINUX 65361

# define PLUS_LINUX 61
# define MINUS_LINUX 45

# define KEY_K_LINUX 107
# define KEY_J_LINUX 106
# define KEY_L_LINUX 108
# define KEY_H_LINUX 104

// LINUX MOUSE
# define MOUSE_UP 4
# define MOUSE_DOWN 5

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
	double		pos_x;
	double		pos_y;
	double		zoom;
	int			max_iter;
}				t_fractol;

// hooks
void		hook_handler(t_fractol *fractol);

// mlx_utils
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);

// utils
void		init_scale_real(t_scale *scale_real, int x);
void		init_scale_imag(t_scale *scale_imag, int y);
void		init_scale_color(t_scale *scale_color, int i);
double		interpolate(t_scale *scale);
double		ft_atodob(const char *str);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z_1);

// fractals
void		draw_mandelbrot(t_fractol *fractol);

#endif
