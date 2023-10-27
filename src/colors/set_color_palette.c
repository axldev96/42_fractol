/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_palette.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:39:00 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/27 02:29:12 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_color_palette(t_fractol *fractol)
{
	fractol->color_palette.colors[0].color1 = 0x001B1A17;
	fractol->color_palette.colors[0].color2 = 0x00CF7500;
	fractol->color_palette.colors[1].color1 = 0x003D30A2;
	fractol->color_palette.colors[1].color2 = 0x00B15EFF;
	fractol->color_palette.colors[2].color1 = 0x0097FEED;
	fractol->color_palette.colors[2].color2 = 0x00FC2947;
	fractol->color_palette.colors[3].color1 = 0x00F9F871;
	fractol->color_palette.colors[3].color2 = 0x00FF5200;
	fractol->color_palette.colors[4].color1 = 0x00451952;
	fractol->color_palette.colors[4].color2 = 0x00FFEBEB;
	fractol->color_palette.colors[5].color1 = 0x00FD8D14;
	fractol->color_palette.colors[5].color2 = 0x00DF2E38;
	fractol->color_palette.colors[6].color1 = 0x003DA4AB;
	fractol->color_palette.colors[6].color2 = 0x00000839;
	fractol->color_palette.colors[7].color1 = 0x00EDF7FA;
	fractol->color_palette.colors[7].color2 = 0x00FF502F;
	fractol->color_palette.colors[8].color1 = 0x00FDF6EC;
	fractol->color_palette.colors[8].color2 = 0x00F0A500;
}
