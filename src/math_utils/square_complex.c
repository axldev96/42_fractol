/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_complex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:55:15 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/14 20:01:02 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// General formula:
// (x_real + y_imaginary)^2
// (x + yi) * (x + yi)
// x^2 + xyi + xyi + y^2i^2
// x^2 + 2xyi - y^2
// real value->(x^2 - y^2) + (2xyi)<- imaginary value
// simple square:
// real = (x^2 - y^2)
// imag = 2*x*y
t_complex	square_complex(t_complex z_1)
{
	t_complex	z_2;

	z_2.real = (z_1.real * z_1.real) - (z_1.imag * z_1.imag);
	z_2.imag = 2 * z_1.real * z_1.imag;
	return (z_2);
}
