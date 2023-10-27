/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:11:31 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/27 01:52:25 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_hook(int keycode, t_fractol *fractol)
{
	if (keycode == ARROW_UP || keycode == KEY_K)
		fractol->pos_y -= (0.5 * fractol->zoom);
	else if (keycode == ARROW_DOWN || keycode == KEY_J)
		fractol->pos_y += (0.5 * fractol->zoom);
	else if (keycode == ARROW_RIGHT || keycode == KEY_L)
		fractol->pos_x += (0.5 * fractol->zoom);
	else if (keycode == ARROW_LEFT || keycode == KEY_H)
		fractol->pos_x -= (0.5 * fractol->zoom);
}

void	iters_hook(int keycode, t_fractol *fractol)
{
	if (keycode == PLUS)
		fractol->max_iter += 5;
	if (keycode == MINUS && fractol->max_iter > 6)
		fractol->max_iter -= 5;
}

void	reset_hook(int keycode, t_fractol *fractol)
{
	if (keycode != KEY_R)
		return ;
	fractol->max_iter = MAX_ITER;
	fractol->zoom = 4.0;
	fractol->pos_x = 0.0;
	fractol->pos_y = 0.0;
	fractol->is_fixed = 0;
	fractol->color_type = 0;
	fractol->power = 2;
	fractol->set_colors = 0;
}

void	zoom_hook(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_W)
		fractol->zoom /= 1.4;
	else if (keycode == KEY_S)
		fractol->zoom *= 1.4;
}

void	color_type(int keycode, t_fractol *fractol)
{
	if (keycode != KEY_Z)
		return ;
	if (fractol->color_type == 0)
		fractol->color_type = 1;
	else if (fractol->color_type == 1)
		fractol->color_type = 2;
	else if (fractol->color_type == 2)
		fractol->color_type = 3;
	else if (fractol->color_type == 3)
		fractol->color_type = 0;
}
