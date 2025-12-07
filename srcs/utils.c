/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:08:38 by edblazqu          #+#    #+#             */
/*   Updated: 2025/12/07 17:08:39 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static double	ft_atof_second(char *s, int decimal, int neg)
{
	int		i;
	double	frac;
	double	result;

	result = 0.0;
	i = 0;
	if (neg == -1)
		i = 1;
	frac = 0.1;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (i < decimal || decimal == -1)
				result = result * 10 + s[i] - '0';
			else if (i > decimal)
			{
				result += (s[i] - '0') * frac;
				frac *= 0.1;
			}
		}
		i++;
	}
	return (result);
}

double	ft_atof(char *s)
{
	int		neg;
	int		decimal;
	int		i;

	neg = 1;
	decimal = -1;
	i = 0;
	if (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (i == 0 || (i == 1 && neg == -1))
				return (0.0);
			decimal = i;
		}
		i++;
	}
	return (ft_atof_second(s, decimal, neg) * neg);
}
