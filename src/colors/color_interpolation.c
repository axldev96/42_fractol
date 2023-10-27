/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_interpolation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 07:04:55 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/26 09:14:59 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdint.h>

void	get_final_color_value(double target_range, double dst,
		double original_range, t_trgb *trgb)
{
	trgb->t = trgb->t1 + (uint8_t)(target_range * dst / original_range)
		* (trgb->t2 - trgb->t1) / 255;
	trgb->r = trgb->r1 + (uint8_t)(target_range * dst / original_range)
		* (trgb->r2 - trgb->r1) / 255;
	trgb->g = trgb->g1 + (uint8_t)(target_range * dst / original_range)
		* (trgb->g2 - trgb->g1) / 255;
	trgb->b = trgb->b1 + (uint8_t)(target_range * dst / original_range)
		* (trgb->b2 - trgb->b1) / 255;
}

double	interpolate_colors_bits(t_scale *scale, t_color colors)
{
	const double	target_range = scale->target_max - scale->target_min;
	const double	dst = scale->value_to_scale - scale->original_min;
	const double	original_range = scale->original_max - scale->original_min;
	t_trgb			trgb;

	trgb.t1 = get_t(colors.color1);
	trgb.t2 = get_t(colors.color2);
	trgb.r1 = get_r(colors.color1);
	trgb.r2 = get_r(colors.color2);
	trgb.g1 = get_g(colors.color1);
	trgb.g2 = get_g(colors.color2);
	trgb.b1 = get_b(colors.color1);
	trgb.b2 = get_b(colors.color2);
	get_final_color_value(target_range, dst, original_range, &trgb);
	trgb.color = create_trgb(trgb.t, trgb.r, trgb.g, trgb.b);
	return ((double)trgb.color);
}
