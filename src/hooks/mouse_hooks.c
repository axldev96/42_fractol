/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 08:10:54 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/21 08:12:41 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook_mouse_handler(int action, int x, int y, t_fractol *fractol)
{
	t_scales	mouse_scales;
	double		new_pos_x;
	double		new_pos_y;

	init_t_scales(&mouse_scales);
	init_scale_real(&mouse_scales.scale_real, x);
	init_scale_imag(&mouse_scales.scale_imag, y);
	new_pos_x = (interpolate(&mouse_scales.scale_real)
			* fractol->zoom) + fractol->pos_x;
	new_pos_y = (interpolate(&mouse_scales.scale_imag)
			* fractol->zoom) + fractol->pos_y;
	if (action == MOUSE_UP)
		fractol->zoom *= 1.3;
	else if (action == MOUSE_DOWN)
		fractol->zoom /= 1.3;
	fractol->pos_x = new_pos_x;
	fractol->pos_y = new_pos_y;
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
	if (!fractol)
		return (0);
	if (x < 0 || x > WIDTH)
		return (1);
	if (y < 0 || y > HEIGHT)
		return (1);
	printf("x: %i\ty: %i\n", x, y);
	return (1);
}