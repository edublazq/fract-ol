/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:06:18 by bamberger12       #+#    #+#             */
/*   Updated: 2025/10/29 13:06:19 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_complex	new_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

t_complex	add_complex(t_complex a, t_complex b)
{
	return (new_complex(a.re + b.re, a.im + b.im));
}

t_complex	sustract_complex(t_complex a, t_complex b)
{
	return (new_complex(a.re - b.re, a.im - b.im));
}

t_complex	mult_complex(t_complex a, t_complex b)
{
	return (new_complex(a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re));
}

double	complex_mod(t_complex z)
{
	return (sqrt(z.re * z.re + z.im * z.im));
}
