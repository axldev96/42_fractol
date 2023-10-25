/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:30:30 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/25 11:33:42 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	add_complex(t_complex z_1, t_complex z_2)
{
	t_complex	z_3;

	z_3.real = z_1.real + z_2.real;
	z_3.imag = z_1.imag + z_2.imag;
	return (z_3);
}
