/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:10:59 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/25 16:24:38 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	power_complex(t_complex z, int power)
{
	t_complex	result;
	int			i;

	i = 1;
	if (power == 0)
		return (result.real = 0, result.imag = 1, result);
	else if (power == 1)
		return (z);
	result = z;
	while (i < power)
	{
		result = mult_complex(z, result);
		i++;
	}
	return (result);
}
