/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_abs_velue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:40:38 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/23 17:42:05 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	complex_abs_value(t_complex z_1)
{
	return (sqrt(z_1.real * z_1.real + z_1.imag * z_2.imag));
}
