/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help_usage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 05:06:16 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/21 05:59:52 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help_usage(void)
{
	ft_printf("\n");
	ft_printf("Usage: ./fractol Mandelbrot | Julia <c-real> <c-imaginary>\n");
	ft_printf("Render fractals using the specified type.\n");
	ft_printf("\n");
	ft_printf("Examples:\n");
	ft_printf("./fractol Mandelbrot\n");
	ft_printf("./fractol Julia 0.355 0.355\n");
	ft_printf("\n");
	exit(EXIT_FAILURE);
}
