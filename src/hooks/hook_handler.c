/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:46:07 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/14 20:01:39 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_hook(t_fractol *fractol)
{
	mlx_destroy_image(fractol->vars.mlx, fractol->data.img);
	mlx_destroy_window(fractol->vars.mlx, fractol->vars.win);
	mlx_destroy_display(fractol->vars.mlx);
	free(fractol->vars.mlx);
	exit(EXIT_SUCCESS);
}

int	hook_key_press(int keycode, t_fractol *fractol)
{
	if (keycode == ESCAPE_LINUX)
		close_hook(fractol);
	return (0);
}

void	hook_handler(t_fractol *fractol)
{
	mlx_hook(fractol->vars.win, KeyPress, KeyPressMask, hook_key_press,
		fractol);
}
