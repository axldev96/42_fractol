/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fabs_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:16:53 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/25 21:19:51 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	fabs_complex(t_complex c)
{
	t_complex	result;

	result.real = fabs(c.real);
	result.imag = fabs(c.imag);
	return (result);
}
