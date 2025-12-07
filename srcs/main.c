/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:42:57 by bamberger12       #+#    #+#             */
/*   Updated: 2025/10/29 11:42:58 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_complex	c;
	t_complex	z;
	t_view		v;

	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./fractol mandelbrot/julia", 2);
		return (1);
	}
	start_mlx(&mlx);
	main_hooks(&mlx);
	draw_julia(&mlx, &(mlx.v));
	mlx_loop(mlx.main);
	return (0);
}
