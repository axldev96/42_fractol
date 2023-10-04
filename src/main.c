/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:49:08 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/04 02:34:20 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

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

int	main(void)
{
	int		color;
	t_vars	vars;
	t_data	data;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Mandelbrot Fractal");
	data.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length,
			&data.endian);
	color = 0;
	draw_mandelbrot(&data, color);
	mlx_put_image_to_window(vars.mlx, vars.win, data.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, hook_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
