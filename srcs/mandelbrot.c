/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:36:36 by bamberger12       #+#    #+#             */
/*   Updated: 2025/10/29 13:36:37 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_complex	power_complex(t_complex z, int power)
{
	double		alpha;
	double		mod;
	double		mod_powered;
	t_complex	result;

	alpha = atan2(z.im, z.re);
	mod = complex_mod(z);
	mod_powered = pow(mod, power);
	result = new_complex(mod_powered * cos(power * alpha), mod_powered
			* sin(power * alpha));
	return (result);
}

int	mandelbrot(t_complex constant, size_t max_iter)
{
	t_complex	z;
	size_t		i;

	z = new_complex(0, 0);
	i = 0;
	while (i < max_iter && complex_mod(z) < 4.0)
	{
		z = add_complex(power_complex(z, 2), constant);
		i++;
	}
	return ((int)i);
}
