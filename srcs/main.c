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

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac < 2 || (ft_strncmp(av[1], "mandelbrot", 11)
			&& ft_strncmp(av[1], "julia", 5)))
		pls_exit();
	if (ft_strncmp(av[1], "julia", 5) == 0)
	{
		mlx.fractal_type = JULIA;
		if (ac != 4)
			pls_exit();
		mlx.c.re = ft_atof(av[2]);
		mlx.c.im = ft_atof(av[3]);
		if (!mlx.c.re || !mlx.c.im)
			pls_exit();
	}
	else if (ac == 2)
		mlx.fractal_type = MANDELBROT;
	else
		pls_exit();
	start_mlx(&mlx);
	main_hooks(&mlx);
	draw_it(&mlx, &(mlx.v), mlx.fractal_type);
	mlx_loop(mlx.main);
	return (0);
}
