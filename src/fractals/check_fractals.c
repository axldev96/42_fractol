/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:12:31 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/24 11:40:09 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iter_doubles(char **av, int *dot_flag)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (av[++i])
	{
		j = -1;
		if (av[i][0] == '+' || av[i][0] == '-')
			j++;
		*dot_flag = 0;
		while (av[i][++j])
		{
			if (*dot_flag == 0 && av[i][j] == '.')
			{
				*dot_flag = 1;
				j++;
			}
			if (!ft_isdigit(av[i][j]))
				return (0);
		}
	}
	return (1);
}

static int	check_doubles(char **av)
{
	int		dot_flag;
	double	dbl_1;
	double	dbl_2;

	dot_flag = 0;
	dbl_1 = 0.0;
	dbl_2 = 0.0;
	if (ft_strlen(av[2]) > MAX_LEN_DBL || ft_strlen(av[3]) > MAX_LEN_DBL)
		return (0);
	if (!iter_doubles(av, &dot_flag))
		return (0);
	dbl_1 = ft_strtod(av[2]);
	dbl_2 = ft_strtod(av[3]);
	if (dbl_1 > DBL_MAX || dbl_1 < -DBL_MAX
		|| dbl_2 > DBL_MAX || dbl_2 < -DBL_MAX)
		return (0);
	return (1);
}

void	check_fractal(t_fractol *fractol, int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 10)
		&& ft_strlen(av[1]) == 10)
		fractol->fractal_name = "Mandelbrot";
	else if (ac == 4 && !ft_strncmp(av[1], "Julia", 5) && check_doubles(av)
		&& ft_strlen(av[1]) == 5)
		fractol->fractal_name = "Julia";
	else if (ac == 2 && !ft_strncmp(av[1], "Julia Sin", 9) && ft_strlen(av[1]) == 9)
		fractol->fractal_name = "Julia Sin";
	else
		fractol->fractal_name = NULL;
}
