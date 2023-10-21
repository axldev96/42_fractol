/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:11:31 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/21 04:58:56 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_hook(t_fractol *fractol)
{
	mlx_destroy_image(&fractol->vars.mlx, fractol->data.img);
	mlx_destroy_window(&fractol->vars.mlx, fractol->vars.win);
	free(fractol->vars.mlx);
	exit(EXIT_SUCCESS);
}

void	move_hook(int keycode, t_fractol *fractol)
{
	if (keycode == ARROW_UP || keycode == KEY_K)
		fractol->pos_y += (0.5 * fractol->zoom);
	else if (keycode == ARROW_DOWN || keycode == KEY_J)
		fractol->pos_y -= (0.5 * fractol->zoom);
	else if (keycode == ARROW_RIGHT || keycode == KEY_L)
		fractol->pos_x += (0.5 * fractol->zoom);
	else if (keycode == ARROW_LEFT || keycode == KEY_H)
		fractol->pos_x -= (0.5 * fractol->zoom);
}

void	iters_hook(int keycode, t_fractol *fractol)
{
	if (keycode == PLUS)
		fractol->max_iter += 3;
	if (keycode == MINUS && fractol->max_iter > 5)
		fractol->max_iter -= 3;
}

void	reset_hook(int keycode, t_fractol *fractol)
{
	if (keycode != KEY_R)
		return ;
	fractol->max_iter = MAX_ITER;
	fractol->zoom = 1.0;
	fractol->pos_x = 0.0;
	fractol->pos_y = 0.0;
}

void	zoom_hook(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_W)
		fractol->zoom /= 1.3;
	else if (keycode == KEY_S)
		fractol->zoom *= 1.3;
}
