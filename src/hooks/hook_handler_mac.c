/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler_mac.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:45:21 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/19 23:48:13 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_hook(t_fractol *fractol)
{
	mlx_destroy_image(fractol->vars.mlx, fractol->data.img);
	mlx_destroy_window(fractol->vars.mlx, fractol->vars.win);
	free(fractol->vars.mlx);
	exit(EXIT_SUCCESS);
}

void	move_hook(int keycode, t_fractol *fractol)
{
	
	if (keycode == ARROW_UP_MAC || keycode == KEY_K_MAC)
		fractol->pos_y += (0.5 * fractol->zoom);
	else if (keycode == ARROW_DOWN_MAC || keycode == KEY_J_MAC)
		fractol->pos_y -= (0.5 * fractol->zoom);
	else if (keycode == ARROW_RIGHT_MAC || keycode == KEY_L_MAC)
		fractol->pos_x += (0.5 * fractol->zoom);
	else if (keycode == ARROW_LEFT_MAC || keycode == KEY_H_MAC)
		fractol->pos_x -= (0.5 * fractol->zoom);
}

void	iters_hook(int keycode, t_fractol *fractol)
{
	if (keycode == PLUS_MAC)
		fractol->max_iter += 3;
	if (keycode == MINUS_MAC)
		fractol->max_iter -= 3;
}

void	reset_hook(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_R_MAC)
	{
		fractol->max_iter = MAX_ITER;
		fractol->zoom = 1.0;
		fractol->pos_x = 0.0;
		fractol->pos_y = 0.0;
	}
}

void	zoom_hook(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_W_MAC)
		fractol->zoom *= 1.2;
	else if (keycode == KEY_S_MAC)
		fractol->zoom /= 1.2;
}

int	hook_key_handler(int keycode, t_fractol *fractol)
{
	if (keycode == ESCAPE_MAC)
		close_hook(fractol);
	move_hook(keycode, fractol);
	iters_hook(keycode, fractol);
	zoom_hook(keycode, fractol);
	reset_hook(keycode, fractol);
	draw_fractal(fractol);
	return (0);
}

int	hook_mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	if (button == MOUSE_UP_MAC)
		fractol->zoom *= 0.96;
	else if (button == MOUSE_DOWN_MAC)
		fractol->zoom /= 0.96;
	if (x || y)
		draw_fractal(fractol);
	return (0);
}

void	hook_handler_mac(t_fractol *fractol)
{
	mlx_key_hook(fractol->vars.win, hook_key_handler, fractol);
	mlx_mouse_hook(fractol->vars.win, hook_mouse_handler, fractol);
}
