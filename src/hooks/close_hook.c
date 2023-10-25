/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 07:44:43 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/25 21:36:14 by acaceres         ###   ########.fr       */
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
