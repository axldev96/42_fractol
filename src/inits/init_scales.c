/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scales.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 03:22:36 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/24 06:54:26 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_scale_real(t_scale *scale_real, int x)
{
	scale_real->value_to_scale = x;
	scale_real->target_min = -5;
	scale_real->target_max = 5;
	scale_real->original_min = 0;
	scale_real->original_max = WIDTH;
}

void	init_scale_imag(t_scale *scale_imag, int y)
{
	scale_imag->value_to_scale = y;
	scale_imag->target_min = 5;
	scale_imag->target_max = -5;
	scale_imag->original_min = 0;
	scale_imag->original_max = HEIGHT;
}

void	init_scale_color(t_scale *scale_color, int i, t_fractol *fractol)
{
	scale_color->value_to_scale = i;
	if (fractol->color_type == 1)
	{
		scale_color->target_min = BLACK;
		scale_color->target_max = WHITE;
		scale_color->original_max = fractol->max_iter;
		scale_color->original_min = 0;
	}
	else if (fractol->color_type == 2)
	{
		scale_color->target_min = 0x00FF2E02;
		scale_color->target_max = 0x00FF6545;
		scale_color->original_max = MAX_ITER;
		scale_color->original_min = 0x00FE6545;
	}
	else
	{
		scale_color->target_min = 0;
		scale_color->target_max = 500;
		scale_color->original_min = 0;
		scale_color->original_max = MAX_ITER;
	}
}
