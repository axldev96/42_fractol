/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:34:57 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/14 23:21:32 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

//static int	s_chars(char c)
//{
//	return (c == ' '
//		|| c == '\n'
//		|| c == '\f'
//		|| c == '\t'
//		|| c == '\r'
//		|| c == '\v');
//}

double	ft_atodob(const char *str)
{
	double	result;
	char	c;
	char	point;

	result = 0.0;
	c = 1;
	point = 0;
	while (*str)
	{
		if (*str == '.' && point == 0)
		{
			point = 1;
			str++;
		}
		result = (result * 10 + *str++ - '0');
		if (point)
		{
			result = result / 10;
			point = 0;
		}
	}
	return (result * c);
}
