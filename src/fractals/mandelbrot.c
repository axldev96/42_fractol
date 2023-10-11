/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 03:00:31 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/11 10:21:13 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

void	init_scale_real(t_scale *scale_real, int x)
{
	scale.value_to_scale = x;
	scale->target_min = -2;
	scale->target_max = 2;
	scale->original_min = 0;
	scale->original_max = WIDTH;
}

void	init_scale_imag(t_scale *scale_imag, int y)
{
	scale.value_to_scale = y;
	scale->target_min = 2;
	scale->target_max = -2;
	scale->original_min = 0;
	scale->original_max = HEIGHT;
}

void	mandelbrot(int x, int y, t_data *data, t_vars *vars)
{
	t_complex	z;
	t_complex	c;
	t_scale		scale_real;
	t_scale		scale_imag;

	init_scale_real(scale_real);
	init_scale_imag(scale_imag);
	z.real = 0.0;
	z.imag = 0.0;
	c.real = interpolate(scale);
	// How many times iterate: z^2 + c
	// to check if the point scaped
	while (1)
	{
		z = sum_complex(square_complex(z), c);
		// The value's scaped
		if (1)
		{
			ft_mlx_pixel_put();
			return ;
		}
	}
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
