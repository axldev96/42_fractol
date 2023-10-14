/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:49:08 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/14 20:00:22 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_fractol	fractol;

	fractol.vars.mlx = mlx_init();
	if (!fractol.vars.mlx)
		exit(EXIT_FAILURE);
	fractol.vars.win = mlx_new_window(fractol.vars.mlx, WIDTH,
			HEIGHT, "Mandelbrot Fractal");
	fractol.data.img = mlx_new_image(fractol.vars.mlx, WIDTH, HEIGHT);
	fractol.max_iter = MAX_ITER;
	fractol.data.addr = mlx_get_data_addr(fractol.data.img,
			&fractol.data.bpp, &fractol.data.line_length,
			&fractol.data.endian);
	hook_handler(&fractol);
	draw_mandelbrot(&fractol);
	mlx_loop(fractol.vars.mlx);
	return (0);
}
