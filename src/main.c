/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:49:08 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/25 06:13:19 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// mult complex example
//t_complex a;
//t_complex b;
//t_complex r;

//a.real = 3;
//a.imag = 2;

//b.real = 1;
//b.imag = 7;

//r = mult_complex(a, b);
//printf("result = (%f, %f)\n", r.real, r.imag);
//return (0);

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac < 2)
		print_help_usage();
	init_t_fractol(&fractol);
	check_fractal(&fractol, ac, av);
	if (fractol.fractal_name == NULL)
		print_help_usage();
	init_mlx(&fractol);
	init_fractol(&fractol, av);
	hook_handler(&fractol);
	draw_fractal(&fractol);
	mlx_loop(fractol.vars.mlx);
	return (0);
}
