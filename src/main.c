/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:49:08 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/17 23:47:43 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.vars.mlx = mlx_init();
	if (!fractol.vars.mlx)
		exit(EXIT_FAILURE);
	fractol.vars.win = mlx_new_window(fractol.vars.mlx, WIDTH,
			HEIGHT, "Mandelbrot Fractal");
	fractol.data.img = mlx_new_image(fractol.vars.mlx, WIDTH, HEIGHT);
	fractol.data.addr = mlx_get_data_addr(fractol.data.img,
			&fractol.data.bpp, &fractol.data.line_length,
			&fractol.data.endian);
	if (ac > 2)
	{
		fractol.julia.julia_complex.real = ft_strtod(av[2]);
		fractol.julia.julia_complex.imag = ft_strtod(av[3]);
		fractol.fractal_name = "Julia";
	}
	else
		fractol.fractal_name = "Mandelbrot";
	fractol.max_iter = MAX_ITER;
	fractol.zoom = 1.0;
	fractol.pos_x = 0.0;
	fractol.pos_y = 0.0;
	hook_handler_linux(&fractol);
	draw_fractal(&fractol);
	mlx_loop(fractol.vars.mlx);
	return (0);
}
