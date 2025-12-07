/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:47:50 by edblazqu          #+#    #+#             */
/*   Updated: 2025/12/06 15:47:50 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		create_color(int function)
{
	int	color;
	int	r;
	int	g;
	int	b;

	r = (function * 12) % 255;
	g = (function * 5) % 255;
	b = (function * 32) % 255;
	color = (r << 16) | (g << 8) | b;
	return (color);
}

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
        return;
	dst = mlx->addr + (y * mlx->line_len + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

t_complex	map_pxl_to_complex(int x, int y, t_view *v)
{
	t_complex	result;

    result.re = v->min.re + (double)x / (WIDTH - 1) * (v->max.re - v->min.re);
    result.im = v->max.im - (double)y / (HEIGHT - 1) * (v->max.im - v->min.im);
	return (result);
}

