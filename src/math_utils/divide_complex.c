/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_complex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:34:09 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/25 12:14:30 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	divide_complex(t_complex z_1, t_complex z_2)
{
	t_complex	result;
	t_complex	z_2_conj;
	t_complex	numerator;
	t_complex	denominator;

	z_2_conj.real = z_2.real;
	z_2_conj.imag = -z_2.imag;
	numerator = mult_complex(z_1, z_2_conj);
	denominator = mult_complex(z_2, z_2_conj);
	if (denominator.real == 0.0 && denominator.imag == 0.0)
	{
		result.real = NAN;
		result.imag = NAN;
	}
	else
	{
		result.real = numerator.real / (denominator.real);
		result.imag = numerator.imag / (denominator.real);
	}
	return (result);
}
