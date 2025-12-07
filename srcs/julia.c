/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:11:08 by edblazqu          #+#    #+#             */
/*   Updated: 2025/12/07 12:11:09 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	julia(t_complex z, size_t max_iter)
{
	t_complex	constant;
	size_t		i;

	i = 0;
	constant = new_complex(0.3, 0.7);
	while (i < max_iter && complex_mod(z) <= 4.0)
	{
		z = power_complex(z, 2);
		z = add_complex(z, constant);
		i++;
	}
	return ((int)i);
}

void	draw_julia(t_mlx *mlx, t_view *v)
{
	int			x;
	int			y;
	int			function;
	t_complex	z;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z = map_pxl_to_complex(x, y, v);
			function = julia(z, mlx->max_iter);
			if (function == mlx->max_iter)
				put_pixel(mlx, x, y, WHITE);
			else
				put_pixel(mlx, x, y, create_color(function));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->main, mlx->win, mlx->img, 0, 0);
}
