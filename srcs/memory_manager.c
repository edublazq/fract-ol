/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:08:45 by bamberger12       #+#    #+#             */
/*   Updated: 2025/10/29 12:08:46 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	*freedom(t_mlx	*mlx)
{
	free(mlx);
	mlx = NULL;
	return (mlx);
}

void	pls_exit(void)
{
	ft_putstr_fd("Usage: ./fractol mandelbrot/julia (julia: const1 const2)", 2);
	exit(1);
}
