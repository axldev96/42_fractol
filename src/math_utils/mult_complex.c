/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:06:44 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/25 16:15:13 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	mult_complex(t_complex z_1, t_complex z_2)
{
	t_complex	result;

	result.real = z_1.real * z_2.real - z_1.imag * z_2.imag;
	result.imag = z_1.real * z_2.imag + z_1.imag * z_2.real;
	return (result);
}
