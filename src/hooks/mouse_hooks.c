/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 08:10:54 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/27 15:33:18 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	do_zoom(t_fractol *fractol, double new_zoom,
		double new_pos_x, double new_pos_y)
{
	double		final_x;
	double		final_y;
	double		dzoom;

	final_x = new_pos_x - fractol->pos_x;
	final_y = new_pos_y - fractol->pos_y;
	dzoom = fractol->zoom - new_zoom;
	fractol->pos_x += (final_x * TRANSITION_SPEED) / 3;
	fractol->pos_y += (final_y * TRANSITION_SPEED) / 3;
	fractol->zoom += dzoom * TRANSITION_SPEED;
}

int	hook_mouse_handler(int action, int x, int y, t_fractol *fractol)
{
	t_scales	mouse_scales;
	double		new_pos_x;
	double		new_pos_y;
	double		new_zoom;

	new_zoom = 0.0;
	init_t_scales(&mouse_scales);
	init_scale_real(&mouse_scales.scale_real, x);
	init_scale_imag(&mouse_scales.scale_imag, y);
	new_pos_x = (interpolate(&mouse_scales.scale_real)
			* fractol->zoom) + fractol->pos_x;
	new_pos_y = (interpolate(&mouse_scales.scale_imag)
			* fractol->zoom) + fractol->pos_y;
	if (action == MOUSE_UP)
		new_zoom = fractol->zoom / 1.1;
	else if (action == MOUSE_DOWN)
		new_zoom = fractol->zoom / 0.9;
	else
		return (0);
	do_zoom(fractol, new_zoom, new_pos_x, new_pos_y);
	draw_fractal(fractol);
	return (0);
}

int	window_close_hook(t_fractol *fractol)
{
	close_hook(fractol);
	return (0);
}

int	check_mouse_pos(int x, int y, t_fractol *fractol)
{
	t_scales	mouse_scales;
	double		new_real;
	double		new_imag;

	if (fractol->is_fixed)
		return (1);
	if (x < 0 || x > WIDTH)
		return (1);
	if (y < 0 || y > HEIGHT)
		return (1);
	init_t_scales(&mouse_scales);
	init_scale_real(&mouse_scales.scale_real, x);
	init_scale_imag(&mouse_scales.scale_imag, y);
	new_real = (interpolate(&mouse_scales.scale_real)
			* fractol->zoom) + fractol->pos_x;
	new_imag = (interpolate(&mouse_scales.scale_imag)
			* fractol->zoom) + fractol->pos_y;
	fractol->julia.julia_complex.real = new_real;
	fractol->julia.julia_complex.imag = new_imag;
	draw_fractal(fractol);
	return (1);
}
