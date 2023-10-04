/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:49:08 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/04 03:00:58 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
