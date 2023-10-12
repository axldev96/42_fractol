/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:26:04 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/12 13:18:13 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 1024
# define HEIGHT 768
# define MAX_ITER 10

# define ESCAPE_MAC 53
# define ESCAPE_LINUX 65307

# define HYPOTENUSE 4.0

# define BLACK 0x00000000
# define WHITE 0x00FFFFFF

typedef struct s_scale
{
	double	value_to_scale;
	double 	target_min;
	double 	target_max;
	double 	original_min;
	double 	original_max;
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
}			t_complex;

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
	t_complex	complex;
	t_scale		scale;
	t_scales	scales;
	int			max_iter;
}				t_fractol;


// hooks
int	hook_close(int keycode, t_vars *vars);

// mlx_utils
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);

// utils
double		interpolate(t_scale *scale);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z_1);
void		init_scale_real(t_scale *scale_real, int x);
void		init_scale_imag(t_scale *scale_imag, int y);
void		init_scale_color(t_scale *scale_color, int i);

// fractals
void	draw_mandelbrot(t_fractol *fractol);

#endif
