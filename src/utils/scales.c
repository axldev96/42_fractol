/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scales.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:14:01 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/20 07:46:27 by acaceres         ###   ########.fr       */
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

void	init_scale_color(t_scale *scale_color, int i)
{
	scale_color->value_to_scale = i;
	scale_color->target_min = BLACK;
	scale_color->target_max = WHITE;
	scale_color->original_min = 0;
	scale_color->original_max = MAX_ITER;
}
