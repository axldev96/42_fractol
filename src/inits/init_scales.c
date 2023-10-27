/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scales.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 03:22:36 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/27 02:43:18 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_scale_real(t_scale *scale_real, int x)
{
	scale_real->value_to_scale = x;
	scale_real->target_min = -2;
	scale_real->target_max = 2;
	scale_real->original_min = 0;
	scale_real->original_max = WIDTH;
}

void	init_scale_imag(t_scale *scale_imag, int y)
{
	scale_imag->value_to_scale = y;
	scale_imag->target_min = -2;
	scale_imag->target_max = 2;
	scale_imag->original_min = 0;
	scale_imag->original_max = HEIGHT;
}

void	init_scale_color(t_scale *scale_color, int i, t_fractol *fractol)
{
	scale_color->value_to_scale = i;
	if (fractol->color_type == 0)
		type_zero(scale_color);
	else if (fractol->color_type == 1)
		type_one(scale_color, fractol);
	else if (fractol->color_type == 2)
		type_two(scale_color, fractol);
	else if (fractol->color_type == 3)
		type_three(scale_color, fractol);
}
