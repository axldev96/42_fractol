/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:43:05 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/27 02:42:44 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	type_zero(t_scale *scale_color)
{
	scale_color->target_min = 0;
	scale_color->target_max = 250;
	scale_color->original_min = 0;
	scale_color->original_max = MAX_ITER * 2;
}

void	type_one(t_scale *scale_color, t_fractol *fractol)
{
	scale_color->target_min = BLACK;
	scale_color->target_max = WHITE;
	scale_color->original_min = 0;
	scale_color->original_max = fractol->max_iter;
}

void	type_two(t_scale *scale_color, t_fractol *fractol)
{
	scale_color->target_min = 0x00F99417;
	scale_color->target_max = 0x00F99417;
	scale_color->original_min = 0x00363062;
	scale_color->original_max = fractol->max_iter;
}

void	type_three(t_scale *scale_color, t_fractol *fractol)
{
	scale_color->target_min = 0x00C63D2F;
	scale_color->target_max = 0x00FFBB5C;
	scale_color->original_min = 0;
	scale_color->original_max = fractol->max_iter;
}
