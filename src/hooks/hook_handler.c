/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:23:56 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/25 21:35:52 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fix_image(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_F && !fractol->is_fixed)
		fractol->is_fixed = 1;
	else if (keycode == KEY_F && fractol->is_fixed)
		fractol->is_fixed = 0;
}

void	power_up(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_P)
		fractol->power += 1;
}

int	hook_key_handler(int keycode, t_fractol *fractol)
{
	if (keycode == ESCAPE)
		close_hook(fractol);
	fix_image(keycode, fractol);
	move_hook(keycode, fractol);
	iters_hook(keycode, fractol);
	zoom_hook(keycode, fractol);
	reset_hook(keycode, fractol);
	color_type(keycode, fractol);
	power_up(keycode, fractol);
	draw_fractal(fractol);
	return (0);
}

void	hook_handler(t_fractol *fractol)
{
	mlx_key_hook(fractol->vars.win, hook_key_handler, fractol);
	mlx_mouse_hook(fractol->vars.win, hook_mouse_handler, fractol);
	mlx_hook(fractol->vars.win, ON_DESTROY, 0, window_close_hook, fractol);
	if (!ft_strncmp(fractol->fractal_name, "Julia", 5))
		mlx_hook(fractol->vars.win, ON_MOUSEMOVE, 0, check_mouse_pos, fractol);
}
