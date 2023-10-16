/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:53:41 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/16 20:20:06 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	s_chars(char c)
{
	return (c == ' '
		|| c == '\n'
		|| c == '\f'
		|| c == '\t'
		|| c == '\r'
		|| c == '\v');
}

double	ft_strtod(const char *str)
{
	double	result;
	int		sign;

	result = 0.0;
	sign = 1;
	while (s_chars(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		str++;
	}
	return (result * sign);
}
