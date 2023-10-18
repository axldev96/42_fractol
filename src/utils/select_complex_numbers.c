/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_complex_numbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:56:57 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/17 23:57:20 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_complex_numbers_mandelbrot(t_complex *z, t_complex *c,
		t_scales *scales, t_fractol *fractol)
{
	z->real = 0.0;
	z->imag = 0.0;
	c->real = (interpolate(&scales->scale_real) * fractol->zoom) + fractol->pos_x;
	c->imag = (interpolate(&scales->scale_imag) * fractol->zoom) + fractol->pos_y;
}

void	set_complex_numbers_julia(t_complex *z, t_complex *c,
		t_scales *scales, t_fractol *fractol)
{
	c->real = fractol->julia.julia_complex.real;
	c->imag = fractol->julia.julia_complex.imag;
	z->real = (interpolate(&scales->scale_real) * fractol->zoom) + fractol->pos_x;
	z->imag = (interpolate(&scales->scale_imag) * fractol->zoom) + fractol->pos_y;
}

void	select_complex_numbers(t_complex *z, t_complex *c,
		t_scales *scales, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->fractal_name, "Julia", 5))
		set_complex_numbers_julia(z, c, scales, fractol);
	else if (!ft_strncmp(fractol->fractal_name, "Mandelbrot", 10))
		set_complex_numbers_mandelbrot(z, c, scales, fractol);
}

