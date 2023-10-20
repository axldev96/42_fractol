/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:14:16 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/20 06:14:35 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractol *fractol)
{
	fractol->vars.mlx = mlx_init();
	if (!fractol->vars.mlx)
		exit(EXIT_FAILURE);
	fractol->vars.win = mlx_new_window(fractol->vars.mlx, WIDTH,
			HEIGHT, "Mandelbrot Fractal");
	fractol->data.img = mlx_new_image(fractol->vars.mlx, WIDTH, HEIGHT);
	fractol->data.addr = mlx_get_data_addr(fractol->data.img,
			&fractol->data.bpp, &fractol->data.line_length,
			&fractol->data.endian);
}
