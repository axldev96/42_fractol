/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 03:00:31 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/11 19:10:13 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

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
			color = interpolate(&scales.scale_color);
			return (color);
		}
		++i;
	}
	return (0x00660066);
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
