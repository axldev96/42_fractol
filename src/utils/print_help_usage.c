/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help_usage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 05:06:16 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/26 01:08:19 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help_usage(void)
{
	printf("\n");
	printf("Usage: ./fractol [fractal_type] [optional_arguments]\n");
	printf("\n");
	printf("Render fractal images with various types.\n");
	printf("\n");
	printf("Available Fractal Types:\n");
	printf("\tMandelbrot:\t\tThe Mandelbrot Set\n");
	printf("\tJulia [c-real c-imag]:\tThe Julia Set with custom constants\n");
	printf("\tBurning Ship:\t\tThe Burning Ship Fractal\n");
	printf("\n");
	printf("Examples:\n");
	printf("\t./fractol Mandelbrot\n");
	printf("\t./fractol Julia -0.2 0.89\n");
	printf("\t./fractol \"Burning_Ship\"\n");
	printf("\n");
	exit(EXIT_FAILURE);
}
