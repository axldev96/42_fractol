/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:53:41 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/20 08:21:32 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	s_chars(char c)
{
	return (c == ' '
		|| c == '\n'
		|| c == '\f'
		|| c == '\t'
		|| c == '\r'
		|| c == '\v');
}

static double	get_dec(const char *str, int *sign, int *i, double dec)
{
	while (str[*i] && s_chars(str[*i]))
		(*i)++;
	if (str[*i] && (str[*i] == '-' || str[*i] == '+'))
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	while (str[*i] && ft_isdigit(str[*i]))
	{
		if (!ft_isdigit(str[*i]))
			return (0);
		dec = dec * 10 + str[*i] - '0';
		(*i)++;
	}
	return (dec);
}

double	ft_strtod(const char *str)
{
	double	dec;
	double	frac;
	double	mult;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	dec = get_dec(str, &sign, &i, 0);
	mult = 0.1;
	frac = 0.0;
	if (str[i] && (str[i] == ',' || str[i] == '.'))
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		if (!ft_isdigit(str[i]))
			return (0);
		frac += (str[i] - '0') * mult;
		mult *= 0.1;
		i++;
	}
	return (sign * (dec + frac));
}
