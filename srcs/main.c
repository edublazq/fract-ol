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

int	close_win(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_loop_end(mlx->main);
		mlx_destroy_window(mlx->main ,mlx->win);
		mlx_destroy_display(mlx->main);
		if (!freedom(mlx))
			exit(0);
		else
			exit(1);
	}
	return(0);
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;
	t_complex	c;
	t_complex	z;

	c = new_complex(1, 1);
	z = power_complex(c, 3);
	printf("%lf + %lfi\n", z.re, z.im);
	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->main = mlx_init();
	mlx->win = mlx_new_window(mlx->main, 800, 600, "Window");
	mlx_hook(mlx->win, 2, 1L<<0, close_win, mlx);
	mlx_loop(mlx->main);
	return (0);
}
