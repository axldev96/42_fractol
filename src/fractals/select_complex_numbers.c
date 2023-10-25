/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_complex_numbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:56:57 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/25 23:10:36 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_complex_numbers_mandelbrot(t_complex *z, t_complex *c,
		t_scales *scales, t_fractol *fractol)
{
	z->real = 0.0;
	z->imag = 0.0;
	c->real = (interpolate(&scales->scale_real)
			* fractol->zoom) + fractol->pos_x;
	c->imag = (interpolate(&scales->scale_imag)
			* fractol->zoom) + fractol->pos_y;
}

void	set_complex_numbers_julia(t_complex *z, t_complex *c,
		t_scales *scales, t_fractol *fractol)
{
	c->real = fractol->julia.julia_complex.real;
	c->imag = fractol->julia.julia_complex.imag;
	z->real = (interpolate(&scales->scale_real)
			* fractol->zoom) + fractol->pos_x;
	z->imag = (interpolate(&scales->scale_imag)
			* fractol->zoom) + fractol->pos_y;
}

void	set_complex_numbers_burning_ship(t_complex *z, t_complex *c,
		t_scales *scales, t_fractol *fractol)
{
	z->real = 0.0;
	z->imag = 0.0;
	c->real = (interpolate(&scales->scale_real) * fractol->zoom)
		+ fractol->pos_x;
	c->imag = (interpolate(&scales->scale_imag) * fractol->zoom)
		+ fractol->pos_y;
}

void	select_complex_numbers(t_complex *z, t_complex *c,
		t_scales *scales, t_fractol *fractol)
{
	if (fractol->fname == Mandelbrot)
		set_complex_numbers_mandelbrot(z, c, scales, fractol);
	else if (fractol->fname == Julia)
		set_complex_numbers_julia(z, c, scales, fractol);
	else if (fractol->fname == Burning_Ship)
		set_complex_numbers_burning_ship(z, c, scales, fractol);
}
