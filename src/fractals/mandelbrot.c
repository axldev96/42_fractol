/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 03:00:31 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/04 03:01:01 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

int	mandelbrot(t_cmpx_nbs c)
{
	t_cmpx_nbs		z;
	int				n;
	double			real_temp;

	z.real = 0;
	z.imag = 0;
	n = 0;
	real_temp = z.real;
	while (n < MAX_ITER)
	{
		real_temp = z.real;
		z.real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * real_temp * z.imag + c.imag;
		if (z.real * z.real + z.imag * z.imag > 4.0)
			return (n);
		n++;
	}
	return (MAX_ITER);
}

void	draw_mandelbrot(t_data *data, int color)
{
	int				x;
	int				y;
	double			real;
	double			imag;
	t_cmpx_nbs		c;

	x = 0;
	y = 0;
	real = 0;
	imag = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
			imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
			c.real = real;
			c.imag = imag;
			color = mandelbrot(c);
			ft_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}

