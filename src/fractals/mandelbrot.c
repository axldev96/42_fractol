/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 03:00:31 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/16 11:43:43 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_complex_numbers(t_complex *z, t_complex *c,
		t_scales *scales, t_fractol *fractol)
{
	z->real = 0.0;
	z->imag = 0.0;
	c->real = (interpolate(&scales->scale_real) * fractol->zoom) + fractol->pos_x;
	c->imag = (interpolate(&scales->scale_imag) * fractol->zoom) + fractol->pos_y;
}

int	mandelbrot(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	t_scales	scales;
	int			color;
	int			i;

	i = 0;
	init_scale_real(&scales.scale_real, x);
	init_scale_imag(&scales.scale_imag, y);
	set_complex_numbers(&z, &c, &scales, fractol);
	while (i < fractol->max_iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imag * z.imag) > HYPOTENUSE)
		{
			init_scale_color(&scales.scale_color, i);
			color = interpolate(&scales.scale_color);
			return (color);
		}
		++i;
	}
	return (BLACK);
}

void	draw_mandelbrot(t_fractol *fractol)
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
			color = mandelbrot(x, y, fractol);
			ft_mlx_pixel_put(&fractol->data, x, y, color);
		}
		ft_mlx_pixel_put(&fractol->data, x, y, WHITE);
	}
	mlx_put_image_to_window(fractol->vars.mlx, fractol->vars.win,
		fractol->data.img, 0, 0);
}
