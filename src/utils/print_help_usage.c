/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help_usage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 05:06:16 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/26 01:45:18 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help_usage(void)
{
	ft_printf("\n");
	ft_printf("Usage: ./fractol [fractal_type] [optional_arguments]\n");
	ft_printf("\n");
	ft_printf("Render fractal images with various types.\n");
	ft_printf("\n");
	ft_printf("Available Fractal Types:\n");
	ft_printf("\tMandelbrot:\t\tThe Mandelbrot Set\n");
	ft_printf("\tJulia [c-real c-imag]:\tThe Julia Set with custom constants\n");
	ft_printf("\tBurning Ship:\t\tThe Burning Ship Fractal\n");
	ft_printf("\n");
	ft_printf("Examples:\n");
	ft_printf("\t./fractol Mandelbrot\n");
	ft_printf("\t./fractol Julia -0.2 0.89\n");
	ft_printf("\t./fractol \"Burning_Ship\"\n");
	ft_printf("\n");
	exit(EXIT_FAILURE);
}
