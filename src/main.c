/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:49:08 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/16 20:22:57 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	double	n = 1.2;

	printf("strtod: %f\n", n);
	return (0);
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
	fractol.max_iter = MAX_ITER;
	fractol.zoom = 1.0;
	fractol.pos_x = 0.0;
	fractol.pos_y = 0.0;
	//hook_handler_mac(&fractol);
	hook_handler_linux(&fractol);
	draw_mandelbrot(&fractol);
	mlx_loop(fractol.vars.mlx);
	return (0);
}
