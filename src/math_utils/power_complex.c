/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:10:59 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/25 11:18:44 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	power_complex(t_complex z, int power)
{
	t_complex	result;
	int			i;

	if (power == 0)
		return (result.real = 0, result.imag = 1, result);
	else if (power == 1)
		return (z);
	i = 1;
	while (i < power)
	{
		result = z;
		result = mult_complex(z, result);
		i++;
	}
	return (result);
}
