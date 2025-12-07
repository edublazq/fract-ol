/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:05:25 by edblazqu          #+#    #+#             */
/*   Updated: 2025/12/07 16:05:25 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	draw_it(t_mlx *mlx, t_view *v, int fractal)
{
	int	x;
	int	y;
	int	f;

	mlx->scale = scale_complex(v);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (fractal == MANDELBROT)
				f = mandelbrot(map_pxl(x, y, mlx->scale, *v), mlx->max_iter);
			else
				f = julia(map_pxl(x, y, mlx->scale, *v), mlx->max_iter, mlx->c);
			if (f == mlx->max_iter)
				put_pixel(mlx, x, y, BLACK);
			else
				put_pixel(mlx, x, y, create_color(f));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->main, mlx->win, mlx->img, 0, 0);
}
