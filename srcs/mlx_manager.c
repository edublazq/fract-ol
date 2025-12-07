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
		mlx_destroy_window(mlx->main, mlx->win);
		mlx_destroy_display(mlx->main);
		free(mlx->main);
		exit(0);
	}
	return (0);
}

int	second_close(t_mlx *mlx)
{
	mlx_loop_end(mlx->main);
	mlx_destroy_image(mlx->main, mlx->img);
	mlx_destroy_window(mlx->main, mlx->win);
	mlx_destroy_display(mlx->main);
	free(mlx->main);
	exit(0);
}

int	handle_zoom(int keycode, int x, int y, t_mlx *mlx)
{
	double	zoom_mult;

	(void) x;
	(void) y;
	if (keycode == 4 || keycode == 5)
	{
		if (keycode == 5)
			zoom_mult = 1.1;
		if (keycode == 4)
			zoom_mult = 0.9;
		mlx->v.max.re *= zoom_mult;
		mlx->v.min.re *= zoom_mult;
		mlx->v.max.im *= zoom_mult;
		mlx->v.min.im *= zoom_mult;
		draw_it(mlx, &(mlx->v), mlx->fractal_type);
	}
	return (0);
}

void	main_hooks(t_mlx *mlx)
{
	mlx_mouse_hook(mlx->win, handle_zoom, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, close_win, mlx);
	mlx_hook(mlx->win, 17, 1L << 0, second_close, mlx);
}

void	start_mlx(t_mlx *mlx)
{
	mlx->main = mlx_init();
	mlx->win = mlx_new_window(mlx->main, WIDTH, HEIGHT, "Fract_ol");
	mlx->img = mlx_new_image(mlx->main, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bpp),
			&(mlx->line_len), &(mlx->endian));
	mlx->max_iter = 50;
	mlx->v.max.re = 1.0;
	mlx->v.max.im = 1.5;
	mlx->v.min.re = -2.0;
	mlx->v.min.im = -1.5;
}
