/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:15:26 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/27 15:09:45 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *fractol, char **av)
{
	fractol->max_iter = MAX_ITER;
	fractol->pos_x = 0.0;
	fractol->pos_y = 0.0;
	fractol->is_fixed = 1;
	fractol->color_type = 0;
	fractol->power = 2;
	fractol->set_colors = 0;
	fractol->zoom = 3.0;
	if (fractol->fname == Julia)
	{
		fractol->julia.julia_complex.real = ft_strtod(av[2]);
		fractol->julia.julia_complex.imag = ft_strtod(av[3]);
	}
}
