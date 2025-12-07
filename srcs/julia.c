/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:11:08 by edblazqu          #+#    #+#             */
/*   Updated: 2025/12/07 12:11:09 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	julia(t_complex z, size_t max_iter, t_complex julia_const)
{
	t_complex	constant;
	size_t		i;

	i = 0;
	while (i < max_iter && complex_mod(z) <= 4.0)
	{
		z = power_complex(z, 2);
		z = add_complex(z, julia_const);
		i++;
	}
	return ((int)i);
}
