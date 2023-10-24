/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtract_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:18:55 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/24 07:46:25 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	subtract_complex(t_complex z_1, t_complex z_2)
{
	t_complex	z_3;
	double		z2_real;
	double		z2_imag;

	z2_real = z_2.real * -1;
	z2_imag = z_2.imag * -1;
	z_3.real = z_1.real + z2_real;
	z_3.imag = z_1.imag + z2_imag;
	return (z_3);
}
