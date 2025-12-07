/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:36:36 by bamberger12       #+#    #+#             */
/*   Updated: 2025/10/29 13:36:37 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_complex	power_complex(t_complex z, int power)
{
	double		alpha;
	double		mod;
	double		mod_powered;
	t_complex	result;

	alpha = atan2(z.im, z.re);
	mod = complex_mod(z);
	mod_powered = pow(mod, power);
	result = new_complex(mod_powered * cos(power * alpha), mod_powered
			* sin(power * alpha));
	return (result);
}

int	mandelbrot(t_complex constant, size_t max_iter)
{
	t_complex	z;
	size_t		i;

	z = new_complex(0, 0);
	i = 0;
	while (i < max_iter && complex_mod(z) < 4.0)
	{
		z = add_complex(power_complex(z, 2), constant);
		i++;
	}
	return ((int)i);
}

void	draw_mandelbrot(t_mlx *mlx, t_view *v)
{
	int			x;
	int			y;
	int			function;
	t_complex	c;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = map_pxl_to_complex(x, y, v);
			function = mandelbrot(c, mlx->max_iter);
			if (function == mlx->max_iter)
				put_pixel(mlx, x, y, BLACK);
			else
				put_pixel(mlx, x, y, create_color(function));
				//put_pixel(mlx, x, y, BLUE * function / mlx->max_iter);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->main, mlx->win, mlx->img, 0, 0);
}
