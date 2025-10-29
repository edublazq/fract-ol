/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:52:55 by bamberger12       #+#    #+#             */
/*   Updated: 2025/10/29 11:52:56 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include "Libft/libft.h"

# define KEY_ESC 65307

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;


typedef struct	s_mlx
{
	int		size_x;
	int		size_y;
	void	*main;
	void	*win;
}	t_mlx;

void	*freedom(t_mlx	*mlx);

//MANDELBROT
t_complex	mandelbrot(t_complex constant, size_t max_iter);

// COMPLEX NUMBERS
t_complex	new_complex(double re, double im);
t_complex	add_complex(t_complex a, t_complex b);
t_complex	sustract_complex(t_complex a, t_complex b);
t_complex	mult_complex(t_complex a, t_complex b);
t_complex	power_complex(t_complex z, int power);
double		complex_mod(t_complex z);

#endif
