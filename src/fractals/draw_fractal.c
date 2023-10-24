/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:23:10 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/24 07:43:54 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// z = subtract_complex(c, square_complex(z)); // inverted mandelbrot
int	calculate_fractal(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	t_scales	scales;
	int			i;

	i = 0;
	init_t_scales(&scales);
	init_scale_real(&scales.scale_real, x);
	init_scale_imag(&scales.scale_imag, y);
	select_complex_numbers(&z, &c, &scales, fractol);
	while (i < fractol->max_iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imag * z.imag) > HYPOTENUSE)
		{
			init_scale_color(&scales.scale_color, i, fractol);
			return (interpolate_color(&scales.scale_color));
		}
		++i;
	}
	return (BLACK);
}

void	draw_fractal(t_fractol *fractol)
{
	int	x;
	int	y;
	int	color;

	color = 0;
	x = -1;
	y = -1;
	while (++x < (WIDTH - 1))
	{
		y = -1;
		while (++y < (HEIGHT - 1))
		{
			color = calculate_fractal(x, y, fractol);
			ft_mlx_pixel_put(&fractol->data, x, y, color);
		}
	}
	mlx_put_image_to_window(fractol->vars.mlx, fractol->vars.win,
		fractol->data.img, 0, 0);
}
