/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:08:06 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/04 04:31:07 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw(t_data *data, int color)
{
	int	iter;
	int	x;
	int	z;
	int	y;

	iter = 0;
	x = 1;
	z = 0;
	while (iter < 10)
	{
		y = 0;
		while (y < HEIGHT)
			ft_mlx_pixel_put(data, y, z, color);
		z = pow(z, 2);
		z++;
		iter++;
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
	// here
	draw(&data, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, data.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, hook_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
