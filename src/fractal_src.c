/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_src.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:24:11 by sehkang           #+#    #+#             */
/*   Updated: 2021/09/03 12:05:25 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mandelbrot(double a, double b, int max)
{
	int		i; 
	double	x;
	double	y;
	double	tmp;

	i = 0;
	x = 0;
	y = 0;
	while (i < MAX_ITER)
	{
		if (x * x + y * y > 4)
			return (i);
		tmp = x * x - y * y + a;
		y = 2 * x * y + b;
		x = tmp;
		i++;
	}
	return (MAX_ITER);
}
