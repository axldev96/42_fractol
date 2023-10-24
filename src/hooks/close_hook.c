/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 07:44:43 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/24 07:44:56 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_hook(t_fractol *fractol)
{
	if (__linux__)
	{
		mlx_destroy_image(fractol->vars.mlx, fractol->data.img);
		mlx_destroy_window(fractol->vars.mlx, fractol->vars.win);
		mlx_destroy_display(fractol->vars.mlx);
	}
	else
	{
		mlx_destroy_image(&fractol->vars.mlx, fractol->data.img);
		mlx_destroy_window(&fractol->vars.mlx, fractol->vars.win);
	}
	free(fractol->vars.mlx);
	exit(EXIT_SUCCESS);
}
