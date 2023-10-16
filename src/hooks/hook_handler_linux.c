/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler_linux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:44:59 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/16 11:45:55 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//void	close_hook(t_fractol *fractol)
//{
//	mlx_destroy_image(fractol->vars.mlx, fractol->data.img);
//	mlx_destroy_window(fractol->vars.mlx, fractol->vars.win);
//	mlx_destroy_display(fractol->vars.mlx);
//	free(fractol->vars.mlx);
//	exit(EXIT_SUCCESS);
//}
//
//void	moves(int keycode, t_fractol *fractol)
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
//void	zoom(int keycode, t_fractol *fractol)
//{
//	if (keycode == PLUS_LINUX)
//		fractol->max_iter += 3;
//	if (keycode == MINUS_LINUX)
//		fractol->max_iter -= 3;
//}
//
//int	hook_key_press(int keycode, t_fractol *fractol)
//{
//	//if (fractol)
//	//	printf("keycode: %d\n", keycode);
//	//return (0);
//	if (keycode == ESCAPE_LINUX)
//		close_hook(fractol);
//	moves(keycode, fractol);
//	zoom(keycode, fractol);
//	draw_mandelbrot(fractol);
//	return (0);
//}
//
//int	hook_mouse(int button, int x, int y, t_fractol *fractol)
//{
//	printf("no: %i%i\n", x, y);
//	//if (fractol)
//	//	printf("button: %d\n", button);
//	//return (0);
//	if (button == MOUSE_UP)
//	{
//		fractol->zoom *= 0.96;
//	}
//	else if (button == MOUSE_DOWN)
//		fractol->zoom /= 0.96;
//	draw_mandelbrot(fractol);
//	return (0);
//}
//
//void	hook_handler_linux(t_fractol *fractol)
//{
//	mlx_hook(fractol->vars.win, KeyPress, KeyPressMask, hook_key_press,
//		fractol);
//	mlx_hook(fractol->vars.win, ButtonPress, ButtonPressMask, hook_mouse,
//		fractol);
//}
