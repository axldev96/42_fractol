/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:49:08 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/12 13:17:50 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(void)
{
	t_fractol	fractol;

	fractol.max_iter = MAX_ITER;
	fractol.vars.mlx = mlx_init();
	fractol.vars.win = mlx_new_window(fractol.vars.mlx, WIDTH,
			HEIGHT, "Mandelbrot Fractal");
	fractol.data.img = mlx_new_image(fractol.vars.mlx, WIDTH, HEIGHT);
	fractol.data.addr = mlx_get_data_addr(fractol.data.img,
			&fractol.data.bpp, &fractol.data.line_length,
			&fractol.data.endian);
	draw_mandelbrot(&fractol);
	mlx_key_hook(fractol.vars.win, hook_close, &fractol.vars);
	mlx_loop(fractol.vars.mlx);
	return (0);
}
