/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:23:10 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/27 02:49:02 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// z = subtract_complex(c, square_complex(z)); // inverted mandelbrot

int	calculate_fractal(int x, int y, t_fractol *fractol)
{
	t_complex		z;
	t_complex		c;
	t_scales		scales;
	int				i;
	const t_color	color = fractol->color_palette.colors[fractol->set_colors];

	i = 0;
	init_t_scales(&scales);
	init_scale_real(&scales.scale_real, x);
	init_scale_imag(&scales.scale_imag, y);
	select_complex_numbers(&z, &c, &scales, fractol);
	while (i < fractol->max_iter)
	{
		if (fractol->fname == Mandelbrot || fractol->fname == Julia)
			z = add_complex(power_complex(z, fractol->power), c);
		else if (fractol->fname == Burning_Ship)
			z = add_complex(power_complex(fabs_complex(z), fractol->power), c);
		if ((z.real * z.real) + (z.imag * z.imag) > HYPOTENUSE)
		{
			init_scale_color(&scales.scale_color, i, fractol);
			return (interpolate_colors_bits(&scales.scale_color, color));
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

	color = BLACK;
	x = -1;
	y = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			color = calculate_fractal(x, y, fractol);
			ft_mlx_pixel_put(&fractol->data, x, y, color);
		}
	}
	mlx_put_image_to_window(fractol->vars.mlx, fractol->vars.win,
		fractol->data.img, 0, 0);
}
