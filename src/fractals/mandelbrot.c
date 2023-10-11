/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 03:00:31 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/11 17:27:59 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

#define NUM_COLORS 5
// Define a gradient color palette

double color_interpolate(t_scale *scale)
{
	int	colors[NUM_COLORS] = {0x00000F, 0x5500AA, 0xFF0000, 0xFFFF00, 0xFFFFFF};
	double target_range = scale->target_max - scale->target_min;
	double dst = scale->value_to_scale - scale->original_min;
	double original_range = scale->original_max - scale->original_min;

	// Map the iteration count to a fractional value between 0 and 1
	double fraction = dst / original_range;

	// Calculate the index of the lower color in the palette
	int lower_color_index = (int)(fraction * (NUM_COLORS - 1));

	// Calculate the interpolation factor between the two neighboring colors
	double factor = fraction * (NUM_COLORS - 1) - lower_color_index;

	// Get the two neighboring colors
	int lower_color = colors[lower_color_index];
	int upper_color = colors[lower_color_index + 1];

	// Interpolate between the colors
	int interpolated_color = (
	    ((int)((1.0 - factor) * ((lower_color >> 16) & 0xFF) + factor * ((upper_color >> 16) & 0xFF)) << 16) |
	    ((int)((1.0 - factor) * ((lower_color >> 8) & 0xFF) + factor * ((upper_color >> 8) & 0xFF)) << 8) |
	    (int)((1.0 - factor) * (lower_color & 0xFF) + factor * (upper_color & 0xFF))
	);

	return interpolated_color;
}

void	set_complex_numbers(t_complex *z, t_complex *c, t_scales *scales)
{
	z->real = 0.0;
	z->imag = 0.0;
	c->real = interpolate(&scales->scale_real);
	c->imag = interpolate(&scales->scale_imag);
}

int	mandelbrot(int x, int y, t_data *data, t_vars *vars)
{
	t_complex	z;
	t_complex	c;
	t_scales	scales;
	int			color;
	int			i;

	i = 0;
	init_scale_real(&scales.scale_real, x);
	init_scale_imag(&scales.scale_imag, y);
	set_complex_numbers(&z, &c, &scales);
	while (i < MAX_ITER)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imag * z.imag) > HYPOTENUSE)
		{
			init_scale_color(&scales.scale_color, i);
			color = color_interpolate(&scales.scale_color);
			return (color);
		}
		++i;
	}
	return (BLACK);
}

void	draw_mandelbrot(t_data *data, t_vars *vars)
{
	int	x;
	int	y;
	int	color;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			color = mandelbrot(x, y, data, vars);
			ft_mlx_pixel_put(data, x, y, color);
		}
		ft_mlx_pixel_put(data, x, y, WHITE);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

//int	mandelbrot(t_cmpx_nbs c)
//{
//	t_cmpx_nbs		z;
//	int				n;
//	double			real_temp;
//
//	z.real = 0;
//	z.imag = 0;
//	n = 0;
//	real_temp = z.real;
//	while (n < MAX_ITER)
//	{
//		real_temp = z.real;
//		z.real = z.real * z.real - z.imag * z.imag + c.real;
//		z.imag = 2 * real_temp * z.imag + c.imag;
//		if (z.real * z.real + z.imag * z.imag > 4.0)
//			return (n);
//		n++;
//	}
//	return (MAX_ITER);
//}
//
//void	draw_mandelbrot(t_data *data)
//{
//	int			x;
//	int			y;
//	int			color;
//	t_cmpx_nbs	c;
//
//	x = 0;
//	y = 0;
//	color = 0;
//	while (x < WIDTH)
//	{
//		y = 0;
//		while (y < HEIGHT)
//		{
//			c.real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
//			c.imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
//			color = mandelbrot(c);
//			ft_mlx_pixel_put(data, x, y, color);
//			y++;
//		}
//		x++;
//	}
//}
