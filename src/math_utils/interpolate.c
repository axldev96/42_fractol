/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 07:54:34 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/25 19:06:15 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate(t_scale *scale)
{
	double	target_range;
	double	dst;
	double	original_range;

	target_range = scale->target_max - scale->target_min;
	dst = scale->value_to_scale - scale->original_min;
	original_range = scale->original_max - scale->original_min;
	return (target_range * dst / original_range + scale->target_min);
}

double	interpolate_color(t_scale *scale)
{
	double	target_range;
	double	dst;
	double	original_range;

	target_range = scale->target_max - scale->target_min;
	dst = scale->value_to_scale - scale->original_min;
	original_range = scale->original_max - scale->original_min;
	return (scale->target_min + target_range * dst / original_range);
}
