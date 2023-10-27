/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_base_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 03:18:27 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/27 14:07:55 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_t_scale(t_scale *scale)
{
	scale->value_to_scale = 0.0;
	scale->target_min = 0.0;
	scale->target_max = 0.0;
	scale->original_min = 0.0;
	scale->original_max = 0.0;
}

void	init_t_scales(t_scales *scales)
{
	init_t_scale(&scales->scale_real);
	init_t_scale(&scales->scale_imag);
	init_t_scale(&scales->scale_color);
}

void	init_t_complex(int len, t_complex **complex)
{
	int	i;

	i = 0;
	while (i < len)
	{
		(complex[i])->real = 0.0;
		(complex[i])->imag = 0.0;
	}
}

void	init_t_fractol(t_fractol *fractol)
{
	fractol->vars.mlx = NULL;
	fractol->vars.win = NULL;
	fractol->data.img = NULL;
	fractol->data.addr = NULL;
	fractol->data.bpp = 0;
	fractol->data.line_length = 0;
	fractol->data.endian = 0;
	fractol->julia.julia_complex.real = 0.0;
	fractol->julia.julia_complex.imag = 0.0;
	fractol->pos_x = 0.0;
	fractol->pos_y = 0.0;
	fractol->zoom = 0.0;
	fractol->fractal_name = NULL;
	fractol->max_iter = 0;
	fractol->set_colors = 0;
	set_color_palette(fractol);
}
