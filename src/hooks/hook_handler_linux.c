/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler_linux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:44:59 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/19 23:36:42 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//void	close_hook_linux(t_fractol *fractol)
//{
//	mlx_destroy_image(fractol->vars.mlx, fractol->data.img);
//	mlx_destroy_window(fractol->vars.mlx, fractol->vars.win);
//	mlx_destroy_display(fractol->vars.mlx);
//	free(fractol->vars.mlx);
//	exit(EXIT_SUCCESS);
//}
//
//void	move_hook_linux(int keycode, t_fractol *fractol)
//{
//	if (keycode == ARROW_UP_LINUX || keycode == KEY_K_LINUX)
//		fractol->pos_y += (0.5 * fractol->zoom);
//	else if (keycode == ARROW_DOWN_LINUX || keycode == KEY_J_LINUX)
//		fractol->pos_y -= (0.5 * fractol->zoom);
//	else if (keycode == ARROW_RIGHT_LINUX || keycode == KEY_L_LINUX)
//		fractol->pos_x += (0.5 * fractol->zoom);
//	else if (keycode == ARROW_LEFT_LINUX || keycode == KEY_H_LINUX)
//		fractol->pos_x -= (0.5 * fractol->zoom);
//}
//
//void	iters_hook_linux(int keycode, t_fractol *fractol)
//{
//	if (keycode == PLUS_LINUX)
//		fractol->max_iter += 3;
//	if (keycode == MINUS_LINUX)
//		fractol->max_iter -= 3;
//}
//
//void	reset_hook_linux(int keycode, t_fractol *fractol)
//{
//	if (keycode == KEY_R_LINUX)
//	{
//		fractol->max_iter = MAX_ITER;
//		fractol->zoom = 1.0;
//		fractol->pos_x = 0.0;
//		fractol->pos_y = 0.0;
//	}
//}
//
//void	hook_zoom_linux(int keycode, t_fractol *fractol)
//{
//	if (keycode == KEY_W_LINUX)
//		fractol->zoom *= 0.96;
//	else if (keycode == KEY_S_LINUX)
//		fractol->zoom /= 0.96;
//}
//
//int	hook_key_press_linux(int keycode, t_fractol *fractol)
//{
//	if (keycode == ESCAPE_LINUX)
//		close_hook_linux(fractol);
//	move_hook_linux(keycode, fractol);
//	iters_hook_linux(keycode, fractol);
//	reset_hook_linux(keycode, fractol);
//	hook_zoom_linux(keycode, fractol);
//	draw_fractal(fractol);
//	return (0);
//}
//
//
//int	hook_mouse_linux(int button, int x, int y, t_fractol *fractol)
//{
//	if (button == MOUSE_UP_LINUX)
//	{
//		fractol->zoom *= 0.96;
//	}
//	else if (button == MOUSE_DOWN_LINUX)
//		fractol->zoom /= 0.96;
//	if (x || y)
//		draw_fractal(fractol);
//	return (0);
//}
//
//void	hook_handler_linux(t_fractol *fractol)
//{
//	mlx_hook(fractol->vars.win, KeyPress, KeyPressMask, hook_key_press_linux,
//		fractol);
//	mlx_hook(fractol->vars.win, ButtonPress, ButtonPressMask, hook_mouse_linux,
//		fractol);
//}
