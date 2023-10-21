/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:15:26 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/20 07:42:55 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *fractol, char **av)
{
	fractol->max_iter = MAX_ITER;
	fractol->zoom = 1.0;
	fractol->pos_x = 0.0;
	fractol->pos_y = 0.0;
	if (!ft_strncmp(fractol->fractal_name, "Julia", 5))
	{
		fractol->julia.julia_complex.real = ft_strtod(av[2]);
		fractol->julia.julia_complex.imag = ft_strtod(av[3]);
	}
}
