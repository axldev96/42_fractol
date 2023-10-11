/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:32:17 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/04 11:34:05 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

int	hook_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
}
