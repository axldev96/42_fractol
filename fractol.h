/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:26:04 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/11 07:45:55 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 1366
# define HEIGHT 768
# define MAX_ITER 1000

# define ESCAPE 65307

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

typedef struct s_cmp_nbs
{
	double	real;
	double	imag;
}			t_cmpx_nbs;

// hooks
int	hook_close(int keycode, t_vars *vars);

// mlx_utils
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);

// utils
double	interpolate(t_scale *scale);

// fractals
void	draw_mandelbrot(t_data *data);

#endif
