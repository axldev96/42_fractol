/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:49:08 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/21 05:00:03 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac < 2)
		exit(EXIT_FAILURE);
	init_t_fractol(&fractol);
	check_fractal(&fractol, ac, av);
	if (fractol.fractal_name == NULL)
		return (printf("Error in parse"), 0);
	init_mlx(&fractol);
	init_fractol(&fractol, av);
	hook_handler(&fractol);
	draw_fractal(&fractol);
	mlx_loop(fractol.vars.mlx);
	return (0);
}
