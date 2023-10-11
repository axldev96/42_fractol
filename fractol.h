/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:26:04 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/11 15:00:06 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 600
# define HEIGHT 600
# define MAX_ITER 100

# define ESCAPE_MAC 53
# define ESCAPE_LINUX 65307

# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define FUCSIA 0x00EF0F88

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

// hooks
int	hook_close(int keycode, t_vars *vars);

// mlx_utils
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);

// utils
double		interpolate(t_scale *scale);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z_1);

// fractals
void	draw_mandelbrot(t_data *data, t_vars *vars);

#endif
