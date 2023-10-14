/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:50:24 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/14 20:01:10 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sum_complex(t_complex z_1, t_complex z_2)
{
	t_complex	z_3;

	z_3.real = z_1.real + z_2.real;
	z_3.imag = z_1.imag + z_2.imag;
	return (z_3);
}
