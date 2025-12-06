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
		mlx_destroy_window(mlx->main ,mlx->win);
		mlx_destroy_display(mlx->main);
		free(mlx->main);
		exit(0);
	}
}

int	second_close(t_mlx *mlx)
{
		mlx_loop_end(mlx->main);
		mlx_destroy_window(mlx->main ,mlx->win);
		mlx_destroy_image(mlx, mlx->img);
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
	mlx->win = mlx_new_window(mlx->main, 800, 600, "Fract_ol");
	mlx->img = mlx_new_image(mlx->main, 800, 600);
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bpp), 
		&(mlx->size_line), &(mlx->endian));
	printf("MLX->BPP %d MLX->SIZE_LINE %d MLX->ENDIAN %d", mlx->bpp, mlx->size_line, mlx->endian);
}
