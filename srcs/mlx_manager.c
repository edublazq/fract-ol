/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:22:28 by bamberger12       #+#    #+#             */
/*   Updated: 2025/10/30 15:22:31 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	close_win(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_loop_end(mlx->main);
		mlx_destroy_image(mlx->main, mlx->img);
		mlx_destroy_window(mlx->main ,mlx->win);
		mlx_destroy_display(mlx->main);
		free(mlx->main);
		exit(0);
	}
}

int	second_close(t_mlx *mlx)
{
	mlx_loop_end(mlx->main);
	mlx_destroy_image(mlx->main, mlx->img);
	mlx_destroy_window(mlx->main ,mlx->win);
	mlx_destroy_display(mlx->main);
	free(mlx->main);
	exit(0);
}

void	main_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L<<0, close_win, mlx);
	mlx_hook(mlx->win, 17, 1L<<0, second_close, mlx);
}

void	start_mlx(t_mlx *mlx)
{
	mlx->main = mlx_init();
	mlx->max_iter = 200;
	mlx->win = mlx_new_window(mlx->main, WIDTH, HEIGHT, "Fract_ol");
	mlx->img = mlx_new_image(mlx->main, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bpp), 
		&(mlx->line_len), &(mlx->endian));
	mlx->v.max.re = 1.0;
	mlx->v.max.im = 1.5;
	mlx->v.min.re = -2.0;
	mlx->v.min.im = -1.5;
}
