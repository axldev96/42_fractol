/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:49:08 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/03 21:17:28 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_cmp_nbs
{
	double	real;
	double	imag;
}			t_cmpx_nbs;

int	mandelbrot(t_cmpx_nbs c)
{
	t_cmpx_nbs		z;
	int				n;
	double			real_temp;

	z.real = 0;
	z.imag = 0;
	n = 0;
	real_temp = z.real;
	while (n < MAX_ITER)
	{
		real_temp = z.real;
		z.real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * real_temp * z.imag + c.imag;
		if (z.real * z.real + z.imag * z.imag > 4.0)
			return (n);
		n++;
	}
	return (MAX_ITER);
}

void	draw_mandelbrot(void *mlx, void *window, int color)
{
	int				x;
	int				y;
	double			real;
	double			imag;
	t_cmpx_nbs		c;

	x = 0;
	y = 0;
	real = 0;
	imag = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
			imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
			c.real = real;
			c.imag = imag;
			color = mandelbrot(c);
			mlx_pixel_put(mlx, window, x, y, color);
			y++;
		}
		x++;
	}
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
}

int	main(void)
{
	int		color;
	void	*mlx;
	void	*window;
	t_data	data;

	mlx = mlx_init();
	window = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot Set");
	color = 0;
	draw_mandelbrot(mlx, window, color);
	mlx_loop(mlx);
	return (0);
}
